#pragma once

#include <Windows.h>
#include <cstdint>
#include <vector>
#include <string>
#include <winnt.h>


struct LeiGodData
{
    unsigned char m_pad0[0x12B8];
    bool m_bSuspend;
    unsigned char m_pad1[0xA7F];

    bool Valid()
    {
        return *(void**)this != nullptr;
    }

};

namespace Hooks
{
    inline void* LeiGodBase;
    inline bool m_bInAccelerate = false;
    inline LeiGodData* m_pLeiGodData = nullptr;
    
    using fnStartAccelerate = int(__fastcall*)(void*, void*, int);
    inline fnStartAccelerate oStartAccelerate = nullptr;
    
    using fnStopAccelerate = int(__fastcall*)(void*, void*, int, int);
    inline fnStopAccelerate oStopAccelerate = nullptr;

    using fnSuspendUserTime = int(__cdecl*)();
    inline fnSuspendUserTime SuspendUserTime = nullptr;

    using fnResumeUserTime = int(__cdecl *)();
    inline fnResumeUserTime oResumeUserTime = nullptr;

	void Initialize();
    void WaitForModule();

    int __fastcall hk_StartAccelerate(void* ecx, void* edx, int a2);
    int __fastcall hk_StopAccelerate(void* ecx, void* edx, int a2, int a3);
    int __cdecl hk_ResumeUserTime();

    static void ThrowError() // ����Ǹ���������
    {
        MessageBoxA(0, "������һ�������Զ���ͣ�Ѿ�����������", "������ͣ���", 0);
    }
}











namespace PatternScan
{
    static unsigned char* Find(void* module, const char* signature)
    {
        static auto pattern_to_byte = [](const char* pattern) {
            auto bytes = std::vector<int>{};
            auto start = const_cast<char*>(pattern);
            auto end = const_cast<char*>(pattern) + strlen(pattern);

            for (auto current = start; current < end; ++current) {
                if (*current == '?') {
                    ++current;
                    if (*current == '?')
                        ++current;
                    bytes.push_back(-1);
                }
                else {
                    bytes.push_back(strtoul(current, &current, 16));
                }
            }
            return bytes;
        };

        auto dosHeader = (PIMAGE_DOS_HEADER)module;
        auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)module + dosHeader->e_lfanew);

        auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
        auto patternBytes = pattern_to_byte(signature);
        auto scanBytes = reinterpret_cast<std::uint8_t*>(module);

        auto s = patternBytes.size();
        auto d = patternBytes.data();

        for (auto i = 0ul; i < sizeOfImage - s; ++i) {
            bool found = true;
            for (auto j = 0ul; j < s; ++j) {
                if (scanBytes[i + j] != d[j] && d[j] != -1) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return &scanBytes[i];
            }
        }
        return nullptr;
    }
}
