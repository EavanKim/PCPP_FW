#pragma once

namespace PCPP
{
	class IComponent
	{
	public:
		explicit IComponent(ITicker* _parent);
		virtual ~IComponent();

		virtual FW_RETURN_CODE Tick(Context_Tick _context) = 0;
		
	private:
		ITicker* m_parent = nullptr;
	};
}