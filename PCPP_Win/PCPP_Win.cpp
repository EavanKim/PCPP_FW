#include <iostream>
#include "ICore.h"
#include "Core_Win.h"

int main(int argc, char* argv[])
{
	std::vector<std::string> argList;
	for (int seek = 0; argc > seek; ++seek)
	{
		argList.push_back(argv[seek]);
	}

	PCPP::ICore* core = new PCPP::Core_Win(argList);

	if (nullptr != core)
	{
		while (core->IsLive())
		{
			core->Tick(1);
		}

		delete core;
		core = nullptr;
	}
}
