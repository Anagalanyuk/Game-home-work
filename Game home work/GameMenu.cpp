#include "GameMenu.h"
#include<iostream>
using namespace std;

char 
Menu(char symbol)
{
	while (symbol != 's' && symbol != 'n' && symbol != 'q')
	{
		cout << "                     Welcome to game" << endl;
		cout << "Press - S - to start game" << endl;
		cout << "Press - n - level selection" << endl;
		cout << "Press - q - exit" << endl;
		cout << "Enter symbol:";
		cin >> symbol;
	}
	return symbol;;
}
