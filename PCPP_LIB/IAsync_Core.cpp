#include "pch.h"

namespace PCPP
{
	IAsync_Core::IAsync_Core()
		: m_context(time(NULL))
	{

	}

	IAsync_Core::~IAsync_Core()
	{

	}

	bool IAsync_Core::IsLive()
	{
		return m_context.HaveState(ExitFlag | ExceptionFlag);
	}
}
