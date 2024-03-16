#pragma once

namespace PCPP
{
	class IAsync_Core
	{
	public:
		explicit IAsync_Core();
		virtual ~IAsync_Core();
		bool IsLive();
		void Stop();
		virtual void Run() = 0;

	private:
		Context_Tick m_context;
	};
}
