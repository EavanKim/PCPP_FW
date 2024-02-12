#pragma once

namespace PCPP
{
	class Context_Tick
	{
	public:
		explicit Context_Tick(time_t _deltaTime)
			: m_startTime(_deltaTime)
			, m_prevTime(_deltaTime)
			, m_nextTime(_deltaTime)
			, m_deltaTime(0)
			, m_stateFlag(0)
		{

		}

		~Context_Tick()
		{

		}

		bool HaveState(FW_RETURN_CODE _flag)
		{
			// 혹시 비교하려는 것이 마스크 상태여서 2개 이상의 플래그를 비교했다면
			// 둘 중 하나만 걸려서 나오는 것 뿐만이 아니라, 완전히 일치하는지 봐야합니다.
			return _flag == (m_stateFlag & _flag);
		}

		FW_RETURN_CODE SetState(FW_RETURN_CODE _flag)
		{
			m_stateFlag |= (FlagMask & _flag);
			return m_stateFlag;
		}

		FW_RETURN_CODE CleanState(FW_RETURN_CODE _flag)
		{
			// 지금 빼려는 플래그를 역전해서, 
			// 삭제 플래그 외의 대상만 And 가능하게 세팅하고, 
			// 현재 flag와 And시키면 빼려는 녀석만 제외하고 결과물이 나옵니다.
			m_stateFlag &= ~(FlagMask & _flag);
			return m_stateFlag;
		}

		FW_RETURN_CODE GetState()
		{
			return m_stateFlag;
		}

		bool CheckInterrupt()
		{
			if (InterruptMask & m_stateFlag)
			{
				return true;
			}

			return false;
		}

		bool CheckExit()
		{
			if (ExitFlag & m_stateFlag)
			{
				return true;
			}

			return false;
		}

		bool CheckSuspend()
		{
			if (SuspendFlag & m_stateFlag)
			{
				return true;
			}

			return false;
		}

		bool CheckException()
		{
			if (ExceptionFlag & m_stateFlag)
			{
				return true;
			}

			return false;
		}

		bool CheckRemove()
		{
			if (RemoveFlag & m_stateFlag)
			{
				return true;
			}

			return false;
		}

		time_t GetTime()
		{
			return m_deltaTime;
		}

		bool Update()
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

	private:
		time_t m_startTime = 0;
		time_t m_prevTime = 0;
		time_t m_nextTime = 0;
		time_t m_deltaTime = 0;
		FW_RETURN_CODE m_stateFlag = 0;
	};
}