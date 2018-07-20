#include<iostream>
using namespace std;

void Printlevel( char** level, char** restart, int rows, int columns, char leftsidebox, char rightsidebox)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (restart[i][j] == '>')
			{
				if (level[i][j] == ' ')
				{
					level[i][j] = '>';
					level[i][j + 1] = '<';
				}
			}
			cout << level[i][j];
		}
		cout << endl;
	}
}
void Conditions()
{
	cout << "r - restat level" << endl;
	cout << "[] - box" << endl;
	cout << ">< - destination" << endl;
	cout << "<D - loader" << endl;
}