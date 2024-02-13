#include "pch.h"

namespace PCPP
{
	ITicker::ITicker(ICore* _parent)
		: m_parent(_parent)
	{

	}
	
	ITicker::~ITicker()
	{
	}

	void ITicker::Tick(Context_Tick& _context)
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
	
	void ITicker::AddComponent(IComponent* _comp)
	{
		m_components.insert(_comp);
	}
	
	void ITicker::RemoveComponent(IComponent* _comp)
	{
		m_components.erase(_comp);
	}
}
