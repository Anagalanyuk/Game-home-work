#ifndef _DRAW_FUNCTIONS_
#define _DRAW_FUNCTIONS_

#include "InGameObjects.h"

using namespace ingameObjects;

namespace drawFunctions
{
	void DrawBorder(const GameField& field);
	void DrawShip(Ship*& ship, const bool isReDraw = false);
	void DrawShots(Shot*& const shots, const int& shotsSize, const bool isReDraw = false);
}

#endif // !_DRAW_FUNCTIONS_

