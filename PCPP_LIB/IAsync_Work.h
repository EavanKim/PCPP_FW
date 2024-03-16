#pragma once
#include <thread>
#include "IAsync_Core.h"

namespace PCPP
{
	class IAsync_Work : public std::thread
	{
	public:
		explicit IAsync_Work(IAsync_Core* _core, bool _isJoinThread = true);
		virtual ~IAsync_Work();

		virtual void Run() = 0;

	private:
		bool m_isJoinThread = true;
		IAsync_Core* m_core = nullptr;
	};
}
