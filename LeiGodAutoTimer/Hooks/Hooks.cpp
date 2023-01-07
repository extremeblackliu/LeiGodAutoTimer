#include "Hooks.h"

#include "minhook/include/MinHook.h"

// 0x6AEC8B55 = 55 8B EC 6A = 函数头 + 0x6A(push指令为了凑整4个字节)
static void* function_walk(void* StartAddress, unsigned int TillByte = 0x6AEC8B55)
{
	unsigned int* m_cStep = (unsigned int*)StartAddress;
	while (*m_cStep != TillByte)
	{
		m_cStep = (unsigned int*)((uintptr_t)m_cStep + 1);
	}
	return m_cStep;
}

namespace Hooks
{
	void WaitForModule()
	{
		while (!GetModuleHandleA("xinput1_3.dll"))
		{
			Sleep(100);
		}

		// 如果用户第一次使用或者上次出现了意外导致时间依旧在流逝，及时停止(FIXME:这个检测可能有问题/不准确/不起作用,尝试使用其他办法,这里是我偷懒了没做直接用的检测的模块加载顺序)
		if (m_pLeiGodData->Valid() && !m_pLeiGodData->m_bSuspend)
		{
			SuspendUserTime();
		}

		return;
	}
	void Initialize()
	{
		LeiGodBase = GetModuleHandle(NULL);
		if (!LeiGodBase)
		{
			ThrowError();
			return;
		}

		if (MH_Initialize() != MH_OK)
		{
			ThrowError();
			return;
		}

		void* StartAccelerate = PatternScan::Find(LeiGodBase, "55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 81 EC ? ? ? ? A1 ? ? ? ? 33 C5 89 45 F0 53 56 57 50 8D 45 F4 64 A3 ? ? ? ? 8B F9 8B 5D 08 8D 8D ? ? ? ? 8B 43 04 83 C0 08 50 E8 ? ? ? ? 68 ? ? ? ? 8D 85 ? ? ? ? C7 45 ? ? ? ? ? 6A 00 50");
		if (!StartAccelerate)
		{
			ThrowError();
			return;
		}
		
		// 重复特征码太多，直接用相邻函数找到下一个函数，找的方法请阅读 function_walk 函数
		void* pResumeUserTime = function_walk(PatternScan::Find(LeiGodBase, "FF 90 ? ? ? ? 8B 46 04 6A 01"));
		if (!pResumeUserTime)
		{
			ThrowError();
			return;
		}
		// 同上，但是和上面的函数相邻，这两个都是雷神的包装函数
		void* pSuspendUserTime = function_walk((void*)((uintptr_t)pResumeUserTime + 0x4));
		if (!pSuspendUserTime)
		{
			ThrowError();
			return;
		}
		SuspendUserTime = (fnSuspendUserTime)pSuspendUserTime;

		void* pStopAccelerate = PatternScan::Find(LeiGodBase, "55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 81 EC ? ? ? ? A1 ? ? ? ? 33 C5 89 45 F0 56 57 50 8D 45 F4 64 A3 ? ? ? ? 8B F9 E8 ? ? ? ? 8B C8");
		if (!pStopAccelerate)
		{
			ThrowError();
			return;
		}
		
		uintptr_t* pLeiGodData = *(uintptr_t**)(PatternScan::Find(LeiGodBase, "A3 ? ? ? ? 8D B8 ? ? ? ? 8B D7 8D 8D ? ? ? ? E8 ? ? ? ? 84 C0") + 1);

		m_pLeiGodData = (LeiGodData*)pLeiGodData;

		MH_CreateHook(StartAccelerate, hk_StartAccelerate, (void**)&oStartAccelerate);
		MH_CreateHook(pStopAccelerate, hk_StopAccelerate, (void**)&oStopAccelerate);

		MH_CreateHook(pResumeUserTime, hk_ResumeUserTime, (void**)&oResumeUserTime);

		MH_EnableHook(MH_ALL_HOOKS);
		
		// 如果线程创建失败会导致关闭空句柄产生异常(我记得好像是)，会导致崩溃，这段代码不应该是这么写的，我偷懒了。
		CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)WaitForModule, 0, 0, 0));
	}

	int __fastcall hk_StartAccelerate(void* ecx, void* edx, int a2)
	{
		m_bInAccelerate = true;

		oResumeUserTime();

		return oStartAccelerate(ecx, edx, a2);
	}

	int __fastcall hk_StopAccelerate(void* ecx, void* edx, int a2, int a3)
	{
		m_bInAccelerate = false;

		int iRet = oStopAccelerate(ecx, edx, a2, a3);
		// 按顺序执行
		SuspendUserTime();

		return iRet;
	}

	int __cdecl hk_ResumeUserTime()
	{
		// 避免误操作在没加速的时候反而打开了加速
		if (!m_bInAccelerate)
			return 0;

		return oResumeUserTime();
	}
}
