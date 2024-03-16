#define _CRTDBG_MAP_ALLOC

#define USE_CRT_DEBUG 1
#ifdef USE_CRT_DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#include <stdlib.h>
#include <crtdbg.h>

#include "PCPP_Lib_Header.h"
#include "Core_Win.h"
#include <iostream>

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::vector<std::string> argList;
	for (int seek = 0; argc > seek; ++seek)
	{
		argList.push_back(argv[seek]);
	}

	PCPP::ICore* core = new PCPP::Core_Win(argList);

	if (nullptr != core)
	{
		try
		{
			while (core->IsLive())
			{
				core->Tick();
			}
		}
		catch (...)
		{
			printf("Crash!!! : %i", GetLastError());
		}

		delete core;
		core = nullptr;

		_CrtDumpMemoryLeaks();
	}
}
