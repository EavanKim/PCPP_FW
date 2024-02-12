#pragma once
#include <vector>
#include <string>
#include "IComponent.h"
#include "ITicker.h"

namespace PCPP
{
	class ICore
	{
	public:
		explicit ICore(std::vector<std::string>& _arg, uint64_t _startTick)
			: m_args(std::move(_arg))
			, m_context(time(NULL))
		{

		}

		virtual ~ICore() 
		{
			for (ITicker*& ticker : m_ticker)
			{
				delete ticker;
				ticker = nullptr;
			}

			m_ticker.clear();
		}

		void Add(ITicker*& _ticker)
		{
			m_ticker.insert(_ticker);
		}

		void Remove(ITicker*& _ticker)
		{
			for (std::set<ITicker*>::iterator iter = m_ticker.begin(); m_ticker.end() != iter; ++iter)
			{
				while (_ticker == *iter)
					iter = m_ticker.erase(iter);
			}
		}

		virtual void Tick()
		{
			if (m_context.Update())
			{
				for (std::set<ITicker*>::iterator iter = m_ticker.begin();
					m_context.CheckInterrupt() && (m_ticker.end() != iter);
					m_context.CheckRemove() ? iter = m_ticker.erase(iter) : ++iter)
				{
					m_context.CleanState(RemoveFlag);
					ITicker* Ticker = *iter;
					Ticker->Tick(m_context);
				}
			}
		}

		bool IsLive()
		{
			return m_isLive;
		}

	private:
		virtual time_t GetDeltaTime() = 0;
		
		Context_Tick m_context;
		bool m_isLive = true;
		std::vector<std::string> m_args = {};
		std::set<ITicker*> m_ticker = {};
	};
}

