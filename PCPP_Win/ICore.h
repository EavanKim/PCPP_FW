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
		explicit ICore(std::vector<std::string>& _arg) 
			: m_args(std::move(_arg)) 
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

		virtual uint64_t Tick(uint64_t _deltaTime)
		{
			uint64_t flag = 0;

			for (ITicker*& ticker : m_ticker)
			{
				flag |= ticker->Tick(_deltaTime);
			}

			return flag;
		}

	private:
		std::vector<std::string> m_args;
		std::vector<ITicker*> m_ticker;
	};
}

