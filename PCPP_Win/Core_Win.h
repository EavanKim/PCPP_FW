#pragma once
#include <vector>
#include <Windows.h>
#include "PCPP_Lib_Header.h"

namespace PCPP
{
	class Core_Win : public ICore
	{
	public:
		explicit Core_Win(std::vector<std::string>& _arg);
		virtual ~Core_Win();

		virtual void Tick() override;
	private:

	};
}

