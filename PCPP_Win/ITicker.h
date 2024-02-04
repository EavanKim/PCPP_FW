#pragma once

namespace PCPP
{
	class ITicker
	{
	public:
		uint64_t Tick(uint64_t _deltaTime)
		{
			return 0;
		}

	private:
		std::vector<IComponent*> m_components;
	};
}