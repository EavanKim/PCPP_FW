#pragma once

#include <ctime>

namespace PCPP
{
	class Context_Tick
	{
	public:
		explicit Context_Tick(time_t _startTime);
		virtual ~Context_Tick();

		bool HaveState(FW_RETURN_CODE _flag);
		bool HaveStateCorrectly(FW_RETURN_CODE _flag);

		FW_RETURN_CODE SetState(FW_RETURN_CODE _flag);
		FW_RETURN_CODE CleanState(FW_RETURN_CODE _flag);
		FW_RETURN_CODE GetState();

		bool CheckInterrupt();
		bool CheckExit();
		bool CheckSuspend();
		bool CheckException();
		bool CheckRemove();

		time_t GetTime();

		bool Update();

	private:
		time_t m_startTime = 0;
		time_t m_prevTime = 0;
		time_t m_nextTime = 0;
		time_t m_deltaTime = 0;
		FW_RETURN_CODE m_stateFlag = 0;
	};
}