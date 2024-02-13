#include "pch.h"

namespace PCPP
{
	ICore::ICore(std::vector<std::string>& _arg, uint64_t _startTick)
		: m_args(std::move(_arg))
		, m_context(time(NULL))
	{

	}

	ICore::~ICore()
	{
		for (ITicker* ticker : m_ticker)
		{
			delete ticker;
			ticker = nullptr;
		}

		m_ticker.clear();
	}

	void ICore::Add(ITicker*& _ticker)
	{
		m_ticker.insert(_ticker);
	}

	void ICore::Remove(ITicker*& _ticker)
	{
		for (std::set<ITicker*>::iterator iter = m_ticker.begin(); m_ticker.end() != iter; ++iter)
		{
			while (_ticker == *iter)
				iter = m_ticker.erase(iter);
		}
	}

	void ICore::Tick()
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

	bool ICore::IsLive()
	{
		return !m_context.HaveState(ExitFlag | ExceptionFlag);
	}
}