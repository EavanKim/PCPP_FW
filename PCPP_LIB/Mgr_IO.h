#pragma once

#include "IAsync_Work.h"
#include "IInput_PressAndRelease.h"

namespace PCPP
{
	class Mgr_IO
	{
	public:
		explicit Mgr_IO(IInput_PressAndRelease* _keyboard);
		~Mgr_IO();

	private:
		IInput_PressAndRelease*	m_keyboard	= nullptr;
	};
}

