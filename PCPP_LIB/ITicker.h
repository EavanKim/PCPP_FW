#pragma once
#include <set>

namespace PCPP
{
	class ITicker
	{
	public:
		explicit ITicker(ICore* _parent);
		virtual ~ITicker();

		virtual void Tick(Context_Tick& _context);

		void AddComponent(IComponent* _comp);
		void RemoveComponent(IComponent* _comp);

	private:
		ICore* m_parent = nullptr;
		std::set<IComponent*> m_components;
	};
}