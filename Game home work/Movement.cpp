#include"Steps.h"
#include"key.h"
#include"Restart.h"

char** Move(char** level, char** restart, int rows, int columns, char leftsidebox, char rightsidebox, int key, char loader, char borders)
{

	switch ( key)
	{
	case Key::r:
		level = Restart(level, restart, rows, columns);
		break;
	case Key::left:
		level = StepLeft(level, key, rows, columns, loader, borders, leftsidebox, rightsidebox);
		break;
	case Key::right:
		level = StepRight(level, key, rows, columns, loader, borders, leftsidebox, rightsidebox);
		break;
	case Key::up:
		level = StepUp(level, key, rows, columns, loader, borders, rightsidebox);
		break;
	case Key::down:
		level = StepDown(level, key, rows, columns, loader, borders, rightsidebox);
		break;
	}
	return level;
}