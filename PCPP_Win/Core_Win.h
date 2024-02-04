#pragma once
#include "ICore.h"

namespace PCPP
{
	class Core_Win : public ICore
	{
	public:
		explicit Core_Win(std::vector<std::string>& _arg);
		virtual ~Core_Win();

	private:

	};
}

