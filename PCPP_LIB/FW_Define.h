#pragma once

namespace PCPP
{
	using FW_RETURN_CODE = uint64_t;

	constexpr FW_RETURN_CODE ExitFlag		= 0x80000000000000;
	constexpr FW_RETURN_CODE SuspendFlag	= 0x40000000000000;
	constexpr FW_RETURN_CODE ExceptionFlag	= 0x20000000000000;
	constexpr FW_RETURN_CODE RemoveFlag		= 0x10000000000000;

	constexpr FW_RETURN_CODE InterruptMask	= 0xFF000000000000;
	constexpr FW_RETURN_CODE FlagMask		=   0xFFFFFFFFFFFF;

	class ICore;
	class IComponent;
	class ITicker;
	class Context_Tick;
}