#include "pch.h"

namespace PCPP
{
	IComponent::IComponent(ITicker* _parent)
		: m_parent(_parent)
	{

	}

	IComponent::~IComponent()
	{
		m_parent->RemoveComponent(this);
	}


}