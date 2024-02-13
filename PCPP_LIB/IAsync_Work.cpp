#include "pch.h"

namespace PCPP
{
	void Async_Run(IAsync_Core* _core)
	{
		if (NULL != _core)
		{
			while (_core->IsLive())
			{
				_core->Run();
			}
		}
	}

	IAsync_Work::IAsync_Work(IAsync_Core* _core, bool _isJoinThread)
		: m_core(_core)
		, std::thread(&Async_Run, _core)
		, m_isJoinThread(_isJoinThread)
	{

	}

	IAsync_Work::~IAsync_Work()
	{
		if (m_isJoinThread)
		{
			if (std::thread::joinable())
			{
				std::thread::join();
			}
		}
	}
}
