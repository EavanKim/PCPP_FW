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
			, m_startTime(_startTick)
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
			m_ticker.push_back(_ticker);
		}

		void Remove(ITicker*& _ticker)
		{
			for (std::vector<ITicker*>::iterator iter = m_ticker.begin(); m_ticker.end() != iter; ++iter)
			{
				while (_ticker == *iter)
					iter = m_ticker.erase(iter);
			}
		}

		virtual uint64_t Tick()
		{
			uint64_t flag = 0;

			uint64_t deltaTime = GetDeltaTime();

			for (ITicker*& ticker : m_ticker)
			{
				flag |= ticker->Tick(deltaTime);

				if (0xFF000000000000 & flag)
				{
					m_isLive = false;
					break;
				}
			}

			return flag;
		}

		bool IsLive()
		{
			return m_isLive;
		}

	private:
		virtual uint64_t GetDeltaTime() = 0;

		uint64_t m_startTime = 0;
		uint64_t m_currentTime = 0;
		uint64_t m_deltaTime = 0;
		bool m_isLive = true;
		std::vector<std::string> m_args = {};
		std::vector<ITicker*> m_ticker = {};
	};
}

