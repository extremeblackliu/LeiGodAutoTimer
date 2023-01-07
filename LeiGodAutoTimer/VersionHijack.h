#pragma once
#include <windows.h>

namespace VersionHijack
{
#if _WIN64
#define VERSION_CALL_CONVENTION __fastcall
#else
#define VERSION_CALL_CONVENTION __stdcall
#endif

	FARPROC m_fGetFileVersionInfoA = 0;
	BOOL VERSION_CALL_CONVENTION GetFileVersionInfoA_(LPCSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
	{
		return reinterpret_cast<BOOL(VERSION_CALL_CONVENTION*)(LPCSTR, DWORD, DWORD, LPVOID)>(m_fGetFileVersionInfoA)(lptstrFilename, dwHandle, dwLen, lpData);
	}

	FARPROC m_fGetFileVersionInfoByHandle = 0;
	BOOL VERSION_CALL_CONVENTION GetFileVersionInfoByHandle_(HANDLE hFile, LPBY_HANDLE_FILE_INFORMATION lpFileInformation)
	{
		return reinterpret_cast<BOOL(VERSION_CALL_CONVENTION*)(HANDLE, LPBY_HANDLE_FILE_INFORMATION)>(m_fGetFileVersionInfoByHandle)(hFile, lpFileInformation);
	}

	FARPROC m_fGetFileVersionInfoExA = 0;
	BOOL VERSION_CALL_CONVENTION GetFileVersionInfoExA_(DWORD dwFlags, LPCSTR lpwstrFilename, DWORD  dwHandle, DWORD  dwLen, LPVOID lpData)
	{
		return reinterpret_cast<BOOL(VERSION_CALL_CONVENTION*)(DWORD, LPCSTR, DWORD, DWORD, LPVOID)>(m_fGetFileVersionInfoExA)(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);
	}

	FARPROC m_fGetFileVersionInfoExW = 0;
	BOOL VERSION_CALL_CONVENTION GetFileVersionInfoExW_(DWORD dwFlags, LPCWSTR lpwstrFilename, DWORD  dwHandle, DWORD  dwLen, LPVOID lpData)
	{
		return reinterpret_cast<BOOL(VERSION_CALL_CONVENTION*)(DWORD, LPCWSTR, DWORD, DWORD, LPVOID)>(m_fGetFileVersionInfoExW)(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);
	}

	FARPROC m_fGetFileVersionInfoSizeA = 0;
	DWORD VERSION_CALL_CONVENTION GetFileVersionInfoSizeA_(LPCSTR lptstrFilename, LPDWORD lpdwHandle)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(LPCSTR, LPDWORD)>(m_fGetFileVersionInfoSizeA)(lptstrFilename, lpdwHandle);
	}

	FARPROC m_fGetFileVersionInfoSizeExA = 0;
	DWORD VERSION_CALL_CONVENTION GetFileVersionInfoSizeExA_(DWORD dwFlags, LPCSTR lpwstrFilename, LPDWORD lpdwHandle)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(DWORD, LPCSTR, LPDWORD)>(m_fGetFileVersionInfoSizeExA)(dwFlags, lpwstrFilename, lpdwHandle);
	}

	FARPROC m_fGetFileVersionInfoSizeExW = 0;
	DWORD VERSION_CALL_CONVENTION GetFileVersionInfoSizeExW_(DWORD dwFlags, LPCWSTR lpwstrFilename, LPDWORD lpdwHandle)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(DWORD, LPCWSTR, LPDWORD)>(m_fGetFileVersionInfoSizeExW)(dwFlags, lpwstrFilename, lpdwHandle);
	}

	FARPROC m_fGetFileVersionInfoSizeW = 0;
	DWORD VERSION_CALL_CONVENTION GetFileVersionInfoSizeW_(LPCWSTR lptstrFilename, LPDWORD lpdwHandle)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(LPCWSTR, LPDWORD)>(m_fGetFileVersionInfoSizeW)(lptstrFilename, lpdwHandle);
	}

	FARPROC m_fGetFileVersionInfoW = 0;
	BOOL VERSION_CALL_CONVENTION GetFileVersionInfoW_(LPCWSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
	{
		return reinterpret_cast<BOOL(VERSION_CALL_CONVENTION*)(LPCWSTR, DWORD, DWORD, LPVOID)>(m_fGetFileVersionInfoW)(lptstrFilename, dwHandle, dwLen, lpData);
	}

	FARPROC m_fVerFindFileA = 0;
	DWORD VERSION_CALL_CONVENTION VerFindFileA_(DWORD uFlags, LPCSTR szFileName, LPCSTR szWinDir, LPCSTR szAppDir, LPSTR szCurDir, PUINT puCurDirLen, LPSTR szDestDir, PUINT puDestDirLen)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(DWORD, LPCSTR, LPCSTR, LPCSTR, LPSTR, PUINT, LPSTR, PUINT)>(m_fVerFindFileA)(uFlags, szFileName, szWinDir, szAppDir, szCurDir, puCurDirLen, szDestDir, puDestDirLen);
	}

	FARPROC m_fVerFindFileW = 0;
	DWORD VERSION_CALL_CONVENTION VerFindFileW_(DWORD uFlags, LPCWSTR szFileName, LPCWSTR szWinDir, LPCWSTR szAppDir, LPWSTR szCurDir, PUINT puCurDirLen, LPWSTR szDestDir, PUINT puDestDirLen)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(DWORD, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, PUINT, LPWSTR, PUINT)>(m_fVerFindFileW)(uFlags, szFileName, szWinDir, szAppDir, szCurDir, puCurDirLen, szDestDir, puDestDirLen);
	}

	FARPROC m_fVerInstallFileA = 0;
	DWORD VERSION_CALL_CONVENTION VerInstallFileA_(DWORD uFlags, LPCSTR szSrcFileName, LPCSTR szDestFileName, LPCSTR szSrcDir, LPCSTR szDestDir, LPCSTR szCurDir, LPSTR szTmpFile, PUINT puTmpFileLen)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(DWORD, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPSTR, PUINT)>(m_fVerInstallFileA)(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, puTmpFileLen);
	}

	FARPROC m_fVerInstallFileW = 0;
	DWORD VERSION_CALL_CONVENTION VerInstallFileW_(DWORD uFlags, LPCWSTR szSrcFileName, LPCWSTR szDestFileName, LPCWSTR szSrcDir, LPCWSTR szDestDir, LPCWSTR szCurDir, LPWSTR szTmpFile, PUINT puTmpFileLen)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(DWORD, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, PUINT)>(m_fVerInstallFileW)(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, puTmpFileLen);
	}

	FARPROC m_fVerLanguageNameA = 0;
	DWORD VERSION_CALL_CONVENTION VerLanguageNameA_(DWORD wLang, LPSTR szLang, DWORD cchLang)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(DWORD, LPSTR, DWORD)>(m_fVerLanguageNameA)(wLang, szLang, cchLang);
	}

	FARPROC m_fVerLanguageNameW = 0;
	DWORD VERSION_CALL_CONVENTION VerLanguageNameW_(DWORD wLang, LPWSTR szLang, DWORD cchLang)
	{
		return reinterpret_cast<DWORD(VERSION_CALL_CONVENTION*)(DWORD, LPWSTR, DWORD)>(m_fVerLanguageNameW)(wLang, szLang, cchLang);
	}

	FARPROC m_fVerQueryValueA = 0;
	BOOL VERSION_CALL_CONVENTION VerQueryValueA_(LPCVOID pBlock, LPCSTR lpSubBlock, LPVOID* lplpBuffer, PUINT puLen)
	{
		return reinterpret_cast<BOOL(VERSION_CALL_CONVENTION*)(LPCVOID, LPCSTR, LPVOID*, PUINT)>(m_fVerQueryValueA)(pBlock, lpSubBlock, lplpBuffer, puLen);
	}

	FARPROC m_fVerQueryValueW = 0;
	BOOL VERSION_CALL_CONVENTION VerQueryValueW_(LPCVOID pBlock, LPCWSTR lpSubBlock, LPVOID* lplpBuffer, PUINT puLen)
	{
		return reinterpret_cast<BOOL(VERSION_CALL_CONVENTION*)(LPCVOID, LPCWSTR, LPVOID*, PUINT)>(m_fVerQueryValueW)(pBlock, lpSubBlock, lplpBuffer, puLen);
	}

	void Initialize()
	{
		char m_cSystemDirectory[MAX_PATH] = { '\0' };
		if (GetSystemDirectoryA(m_cSystemDirectory, sizeof(m_cSystemDirectory)) == 0)
			return;

		if (strcat_s(m_cSystemDirectory, sizeof(m_cSystemDirectory), "\\version.dll"))
			return;

		HMODULE m_hModule = LoadLibraryA(m_cSystemDirectory);
		if (!m_hModule)
			return;

		m_fGetFileVersionInfoA = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(1));
		m_fGetFileVersionInfoByHandle = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(2));
		m_fGetFileVersionInfoExA = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(3));
		m_fGetFileVersionInfoExW = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(4));
		m_fGetFileVersionInfoSizeA = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(5));
		m_fGetFileVersionInfoSizeExA = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(6));
		m_fGetFileVersionInfoSizeExW = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(7));
		m_fGetFileVersionInfoSizeW = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(8));
		m_fGetFileVersionInfoW = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(9));
		m_fVerFindFileA = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(10));
		m_fVerFindFileW = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(11));
		m_fVerInstallFileA = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(12));
		m_fVerInstallFileW = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(13));
		m_fVerLanguageNameA = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(14));
		m_fVerLanguageNameW = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(15));
		m_fVerQueryValueA = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(16));
		m_fVerQueryValueW = GetProcAddress(m_hModule, reinterpret_cast<LPCSTR>(17));
	}
}

namespace sneakyevil_DllHijack
{
	void Initialize()
	{
		VersionHijack::Initialize();
	}
}

#pragma comment(linker, "/export:GetFileVersionInfoA@1=GetFileVersionInfoA_,@1")
#pragma comment(linker, "/export:GetFileVersionInfoByHandle@2=GetFileVersionInfoByHandle_,@2")
#pragma comment(linker, "/export:GetFileVersionInfoExA@3=GetFileVersionInfoExA_,@3")
#pragma comment(linker, "/export:GetFileVersionInfoExW@4=GetFileVersionInfoExW_,@4")
#pragma comment(linker, "/export:GetFileVersionInfoSizeA@5=GetFileVersionInfoSizeA_,@5")
#pragma comment(linker, "/export:GetFileVersionInfoSizeExA@6=GetFileVersionInfoSizeExA_,@6")
#pragma comment(linker, "/export:GetFileVersionInfoSizeExW@7=GetFileVersionInfoSizeExW_,@7")
#pragma comment(linker, "/export:GetFileVersionInfoSizeW@8=GetFileVersionInfoSizeW_,@8")
#pragma comment(linker, "/export:GetFileVersionInfoW@9=GetFileVersionInfoW_,@9")
#pragma comment(linker, "/export:VerFindFileA@10=VerFindFileA_,@10")
#pragma comment(linker, "/export:VerFindFileW@11=VerFindFileW_,@11")
#pragma comment(linker, "/export:VerInstallFileA@12=VerInstallFileA_,@12")
#pragma comment(linker, "/export:VerInstallFileW@13=VerInstallFileW_,@13")
#pragma comment(linker, "/export:VerLanguageNameA@14=VerLanguageNameA_,@14")
#pragma comment(linker, "/export:VerLanguageNameW@15=VerLanguageNameW_,@15")
#pragma comment(linker, "/export:VerQueryValueA@16=VerQueryValueA_,@16")
#pragma comment(linker, "/export:VerQueryValueW@17=VerQueryValueW_,@17")