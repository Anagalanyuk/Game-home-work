#include "DrawFunctions.h"
#include "ConsoleFunctions.h"

using namespace consoleFunctions;
using namespace constants;

void drawFunctions::DrawBorder(const ingameObjects::GameField& field)
{
	Position position;
	char symbol = '*';
	for (int i = -1; i <= field.size.width; ++i)
	{
		position.x = constants::X_SHIFT + i;
		position.y = constants::Y_SHIFT - 1;
		Draw(position, symbol);
		position.x = constants::X_SHIFT + i;
		position.y = constants::Y_SHIFT + field.size.height;
		Draw(position, symbol);
	}

	for (int i = -1; i < field.size.height; ++i)
	{
		position.x = constants::X_SHIFT - 1;
		position.y = constants::Y_SHIFT + i;
		Draw(position, symbol);
		position.x = constants::X_SHIFT + field.size.width;
		position.y = constants::Y_SHIFT + i;
		Draw(position, symbol);
	}
}

void drawFunctions::DrawShip(Ship*& ship, const bool isReDraw /*= false*/)
{
	if (nullptr != ship)
	{
		for (int i = 0; i < SHIP_SIZE; ++i)
		{
			if (isReDraw)
				Draw(ship->points[i].position);
			else
				Draw(ship->points[i].position, ship->points[i].symbol);
		}
	}
}

void drawFunctions::DrawShots(Shot*& const shots, const int& shotsSize, const bool isReDraw /*= false*/)
{
	for (int i = 0; i < shotsSize; ++i)
	{
		if (isReDraw)
			Draw(shots[i].point.position);
		else
			Draw(shots[i].point.position, shots[i].point.symbol);
	}
}
