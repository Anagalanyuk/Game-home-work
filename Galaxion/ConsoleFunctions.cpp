#include "ConsoleFunctions.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

void consoleFunctions::Draw(const ingameObjects::Position & position, const char symbol /*= ' '*/)
{
	static const HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { (short)position.x, (short)position.y };
	SetConsoleCursorPosition(outputHandle, coord);
	cout << symbol;
}

constants::Key consoleFunctions::ReadKey()
{
	int key = _getch();
	if (key == 224)
	{
		key = _getch();
	}
	return (constants::Key) key;
}
