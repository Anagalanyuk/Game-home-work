#include "Game fun.h"
#include<iostream>
#include"level_1.h"
#include<Windows.h>
#include<conio.h>
#include"Steps.h"
#include"Search.h"
#include"Key.h"
#include "Functions.h"
#include"Print.h"
#include"GameMenu.h"
#include"SelectLevel.h"

using namespace std;

void StartGame()
{
	const char borders = 178;
	const char loader = 'D';
	const char leftsidebox = '[';
	const char rightsidebox = ']';
	int key = 0;
	int rows = 10;
	int columns = 20;
	char symbol = '0';
	int number = 0;
	symbol = Menu(symbol);
	if (symbol == 'n')
	{
		system("cls");
		number = Select(number);
	}
	if (symbol == 's' || number == 1)
	{
		system("cls");
		char** level_1 = Level_1(rows, columns, borders, loader, leftsidebox, rightsidebox);
		char** Restart1 = Level_1(rows, columns, borders, loader, leftsidebox, rightsidebox);
		while (Finish(level_1, Restart1, rows, columns, leftsidebox) != false)
		{
			cout << "                       level 1" << endl;
			Printlevel(level_1, Restart1, rows, columns, leftsidebox, rightsidebox);
			Conditions();
			key = _getch();
			system("cls");
			level_1 = Move(level_1, Restart1, rows, columns, leftsidebox, rightsidebox, key, loader, borders);

		}
		level_1 = Delete(level_1, rows, columns);
		cout << "\a";
	}
	if (symbol == 's' || number == 2)
	{
		system("cls");
		char** level_2 = Level_2(rows, columns, borders, loader, leftsidebox, rightsidebox);
		char**Restart2 = Level_2(rows, columns, borders, loader, leftsidebox, rightsidebox);
		while (Finish(level_2, Restart2, rows, columns, leftsidebox) != false)
		{
			cout << "                       level 2" << endl;
			Printlevel(level_2, Restart2, rows, columns, leftsidebox, rightsidebox);
			Conditions();
			key = _getch();
			system("cls");
			level_2 = Move(level_2, Restart2, rows, columns, leftsidebox, rightsidebox, key, loader, borders);
		}
		level_2 = Delete(level_2, rows, columns);
		cout << "\a";
	}
	if (symbol == 's' || number == 3)
	{
		system("cls");
		char** level_3 = Level_3(rows, columns, borders, loader, leftsidebox, rightsidebox);
		char**Restart3 = Level_3(rows, columns, borders, loader, leftsidebox, rightsidebox);
		while (Finish(level_3, Restart3, rows, columns, leftsidebox) != false)
		{
			cout << "                       level 3" << endl;
			Printlevel(level_3, Restart3, rows, columns, leftsidebox, rightsidebox);
			Conditions();
			key = _getch();
			system("cls");
			level_3 = Move(level_3, Restart3, rows, columns, leftsidebox, rightsidebox, key, loader, borders);
		}
		cout << "Good bay" << endl;
		level_3 = Delete(level_3, rows, columns);
	}
	else if (symbol == 'q')
	{
		system("cls");
		cout << "Good bay" << endl;
	}
}
