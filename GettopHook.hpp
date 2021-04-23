#pragma once
#include <iostream>
#include "detours.h"

int x(int addy) {
	return (addy - 0x400000 + reinterpret_cast<int>(GetModuleHandleA("RobloxPlayerBeta.exe")));
}

namespace Gettop
{
	uintptr_t r_lua_state = 0;

	int __cdecl sub_154D6F0(int a1) //gettop lol
	{
		r_lua_state = a1;
		return (*(DWORD*)(a1 + 20) - *(DWORD*)(a1 + 24)) >> 4;
	}

	int GettopAddr = x(0x1526A90);

	int GetRState()
	{
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&reinterpret_cast<void*&>(GettopAddr), &sub_154D6F0);
		DetourTransactionCommit();
	
		while (r_lua_state == 0) {
			Sleep(0.001f);
		}

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&reinterpret_cast<void*&>(GettopAddr), &sub_154D6F0);
		DetourTransactionCommit();

		return r_lua_state;
	}
}
