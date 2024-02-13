#pragma once

namespace PCPP
{
	class ICore
	{
	public:
		explicit ICore(std::vector<std::string>& _arg, uint64_t _startTick);
		virtual ~ICore();

		void Add(ITicker*& _ticker);
		void Remove(ITicker*& _ticker);

		virtual void Tick();

		bool IsLive();

	private:
		
		Context_Tick m_context;
		bool m_isLive = true;
		std::vector<std::string> m_args = {};
		std::set<ITicker*> m_ticker = {};
	};
}

