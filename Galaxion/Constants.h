#ifndef _CONSTANTS_
#define _CONSTATNS_

namespace constants
{
	const int X_SHIFT = 4;
	const int Y_SHIFT = 1;
	const int SHIP_SIZE = 6;
	const int FIELD_SIZE_X = 53;
	const int FIELD_SIZE_Y = 26;
	const int FRAME_UPDATE_DELAY = 50;
	enum class Key
	{
		Left = 75,
		Right = 77,
		Space = 32,
		Esc = 27,
		Enter = 13
	};
}

#endif // !_CONSTANTS_

