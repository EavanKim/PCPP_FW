#pragma once

#include <ctime>

/// ==================================================================================
/// 무언가 실행 흐름 하나에 대한 상태를 관리하는 Context입니다.
/// 하나의 Tick 흐름에 대한 관리자로, 하나의 실행 흐름에 단독으로 존재해야만 합니다.
/// 특정 상황에서 프로그램 실행을 정지시켰을 때,
/// 해당 Tick 흐름에 연관된 일련의 처리 흐름에 대한 정보를 획득할 수 있어야 합니다.
/// ==================================================================================

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