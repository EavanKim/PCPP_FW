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

	time_t Core_Win::GetDeltaTime()
	{
		return 0;
	}
}