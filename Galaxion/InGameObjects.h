#ifndef _IN_GAME_OBJECTS_
#define _IN_GAME_OBJECTS_

#include "Constants.h"

using namespace constants;

namespace ingameObjects
{
	struct Size2D
	{
		int width;
		int height;
	};

	struct Position
	{
		int x;
		int y;
	};

	struct Point
	{
		char symbol;
		Position position;
	};

	struct GameField
	{
		Size2D size;
	};

	struct Ship
	{
		int life;
		Position position;
		Point points[SHIP_SIZE];
	};

	struct Shot
	{
		bool isHeroShot;
		Point point;
	};
}

#endif // !_IN_GAME_OBJECTS_

