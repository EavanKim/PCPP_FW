#pragma once

namespace PCPP
{
	class ITicker
	{
	public:
		virtual void Tick(Context_Tick& _context)
		{
			for (std::set<IComponent*>::iterator iter = m_components.begin();
				_context.CheckInterrupt() && (m_components.end() != iter);
				_context.CheckRemove() ? iter = m_components.erase(iter) : ++iter)
			{
				_context.CleanState(RemoveFlag);
				IComponent* component = *iter;
				component->Tick(_context);
			}
		}

		void AddComponent(IComponent* _comp)
		{
			m_components.insert(_comp);
		}

		void RemoveComponent(IComponent* _comp)
		{
			m_components.erase(_comp);
		}

	private:
		std::set<IComponent*> m_components;
	};
}