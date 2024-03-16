#pragma once

namespace PCPP
{
	enum EK
	{
		UNKNOWN = 0x0,
		NUM_0 = 0x30,
		NUM_1,
		NUM_2,
		NUM_3,
		NUM_4,
		NUM_5,
		NUM_6,
		NUM_7,
		NUM_8,
		NUM_9,
		UNDEFINED = 0x40,
		KEY_A,
		KEY_B,
		KEY_C,
		KEY_D,
		KEY_E,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_I,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_M,
		KEY_N,
		KEY_O,
		KEY_P,
		KEY_Q,
		KEY_R,
		KEY_S,
		KEY_T,
		KEY_U,
		KEY_V,
		KEY_W,
		KEY_X,
		KEY_Y,
		KEY_Z,
		EK_MAX
	};

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