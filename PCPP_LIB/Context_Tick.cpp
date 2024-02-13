#include "pch.h"

namespace PCPP
{
	Context_Tick::Context_Tick(time_t _startTime)
		: m_startTime(_startTime)
		, m_prevTime(_startTime)
		, m_nextTime(_startTime)
		, m_deltaTime(0)
		, m_stateFlag(0)
	{

	}

	Context_Tick::~Context_Tick()
	{

	}

	bool Context_Tick::HaveState(FW_RETURN_CODE _flag)
	{
		// 혹시 비교하려는 것이 마스크 상태여서 2개 이상의 플래그를 비교했다면
		// 둘 중 하나만 걸려서 나오는 것 뿐만이 아니라, 완전히 일치하는지 봐야합니다.
		return m_stateFlag & _flag;
	}

	bool Context_Tick::HaveStateCorrectly(FW_RETURN_CODE _flag)
	{
		return _flag == (m_stateFlag & _flag);
	}

	FW_RETURN_CODE Context_Tick::SetState(FW_RETURN_CODE _flag)
	{
		m_stateFlag |= (FlagMask & _flag);
		return m_stateFlag;
	}

	FW_RETURN_CODE Context_Tick::CleanState(FW_RETURN_CODE _flag)
	{
		// 지금 빼려는 플래그를 역전해서, 
		// 삭제 플래그 외의 대상만 And 가능하게 세팅하고, 
		// 현재 flag와 And시키면 빼려는 녀석만 제외하고 결과물이 나옵니다.
		m_stateFlag &= ~(FlagMask & _flag);
		return m_stateFlag;
	}

	FW_RETURN_CODE Context_Tick::GetState()
	{
		return m_stateFlag;
	}

	bool Context_Tick::CheckInterrupt()
	{
		if (InterruptMask & m_stateFlag)
		{
			return true;
		}

		return false;
	}

	bool Context_Tick::CheckExit()
	{
		if (ExitFlag & m_stateFlag)
		{
			return true;
		}

		return false;
	}

	bool Context_Tick::CheckSuspend()
	{
		if (SuspendFlag & m_stateFlag)
		{
			return true;
		}

		return false;
	}

	bool Context_Tick::CheckException()
	{
		if (ExceptionFlag & m_stateFlag)
		{
			return true;
		}

		return false;
	}

	bool Context_Tick::CheckRemove()
	{
		if (RemoveFlag & m_stateFlag)
		{
			return true;
		}

		return false;
	}

	time_t Context_Tick::GetTime()
	{
		return m_deltaTime;
	}

	bool Context_Tick::Update()
	{
		if (CheckExit())
		{
			return false;
		}
		else if (CheckException())
		{
			return false;
		}
		else
		{
			if (CheckSuspend())
			{
				m_nextTime = time(NULL);
				m_prevTime = m_nextTime;
			}
			else
			{
				m_prevTime = m_nextTime;
				m_nextTime = time(NULL);
			}

			m_deltaTime = m_nextTime - m_prevTime;
		}

		return true;
	}
}