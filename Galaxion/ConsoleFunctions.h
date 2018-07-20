#ifndef _CONSOLE_FUNCTIONS_
#define _CONSOLE_FUNCTIONS_

#include "InGameObjects.h"

namespace consoleFunctions
{
	void Draw(const ingameObjects::Position& position, const char symbol = ' ');
	constants::Key ReadKey();
}

#endif // !_CONSOLE_FUNCTIONS_
