// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "GameFunction.h"

DWORD WINAPI ThreadProc(_In_ LPVOID lpParameter)
{

	while (true)
	{

		if (GetAsyncKeyState(VK_F1) & 1)
		{
			GameFunction::GetInstance()->LoginByPassword("1655602282", "test1234");
		}

		if (GetAsyncKeyState(VK_F2) & 1)
		{
			GameFunction::GetInstance()->LaunchGame(0x1A, 0x101);
		}
		Sleep(1);
	}
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
	{
		if (GameFunction::GetInstance()->InitWeGameEv()) 
		{
			CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
		}
		break;
	}
	case DLL_THREAD_ATTACH: 
		break;
	case DLL_THREAD_DETACH: 
		break;
	case DLL_PROCESS_DETACH: 
        break;
    }
    return TRUE;
}

