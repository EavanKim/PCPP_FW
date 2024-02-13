#include "Core_Win.h"

namespace PCPP
{
	Core_Win::Core_Win(std::vector<std::string>& _arg)
		: ICore(_arg, 0)
	{

	}

	Core_Win::~Core_Win()
	{

	}

	void Core_Win::Tick()
	{
		MSG message;
		if (PeekMessageW(&message, NULL, 0, 0, PM_NOREMOVE))
		{

		}

		ICore::Tick();
	}
}