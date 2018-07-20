#include "SelectLevel.h"
#include<iostream>
using namespace std;

int Select(int number)
{
	system("cls");
	cout << "1 - level 1" << endl;
	cout << "2 - level 2" << endl;
	cout << "3 - level 3" << endl;
	cout << "enter number";
	cin >> number;
	return number;
}
