#include<iostream>

using namespace std;

char** Level_1(int rows, int columns, char borders, char loader, char leftsidebox, char rightsidebox)
{
	char** temp = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = new char[columns];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp[i][j] = borders;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		temp[3][i] = borders;
	}
	for (int i = 8; i < 10; i++)
	{
		temp[3][i] = ' ';
	}
	temp[3][10] = '<';
	temp[3][11] = loader;
	for (int i = 12; i < 20; i++)
	{
		temp[3][i] = 178;
	}
	for (int i = 0; i < 6; i++)
	{
		temp[4][i] = borders;
	}
	temp[4][6] = '>';
	temp[4][7] = '<';
	temp[4][8] = leftsidebox;
	temp[4][9] = rightsidebox;
	temp[4][10] = leftsidebox;
	temp[4][11] = rightsidebox;
	temp[4][12] = '>';
	temp[4][13] = '<';
	for (int i = 14; i < 20; i++)
	{
		temp[4][i] = borders;
	}
	for (int i = 0; i < 8; i++)
	{
		temp[5][i] = borders;
	}
	for (int i = 8; i < 12; i++)
	{
		temp[5][i] = ' ';
	}
	for (int i = 12; i < 20; i++)
	{
		temp[5][i] = borders;
	}
	for (int i = 0; i < 8; i++)
	{
		temp[6][i] = borders;
	}
	for (int i = 8; i < 12; i++)
	{
		temp[6][i] = ' ';
	}
	for (int i = 12; i < 20; i++)
	{
		temp[6][i] = borders;
	}
	for (int i = 7; i < 10; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp[i][j] = borders;
		}
	}
	return temp;
}

char** Level_2(int rows, int columns, char borders, char loader, char leftsidebox, char rightsidebox)
{
	char** temp = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = new char[columns];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp[i][j] = borders;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		temp[3][i] = borders;
	}
	temp[3][7] = '<';
	temp[3][8] = loader;
	temp[3][9] = ' ';
	temp[3][10] = ' ';
	temp[3][11] = '>';
	temp[3][12] = '<';

	for (int i = 13; i < 20; i++)
	{
		temp[3][i] = borders;
	}
	for (int i = 0; i < 7; i++)
	{
		temp[4][i] = borders;
	}
	temp[4][7] = ' ';
	temp[4][8] = ' ';
	temp[4][9] = leftsidebox;
	temp[4][10] = rightsidebox;
	temp[4][11] = leftsidebox;
	temp[4][12] = rightsidebox;
	for (int i = 13; i < 20; i++)
	{
		temp[4][i] = borders;
	}
	for (int i = 0; i < 9; i++)
	{
		temp[5][i] = borders;
	}
	for (int i = 9; i < 13; i++)
	{
		temp[5][i] = ' ';
	}
	temp[5][13] = '>';
	temp[5][14] = '<';
	for (int i = 15; i < 20; i++)
	{
		temp[5][i] = borders;
	}
	for (int i = 6; i < 10; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp[i][j] = borders;
		}
	}
	return temp;
}
char** Level_3(int rows, int columns,  char borders, char loader, char leftsidebox, char rightsidebox)
{
	char** temp = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = new char[columns];
	}
	for (int i = 0; i < columns - 4; i++)
	{
		temp[0][i] = borders;
	}
	for (int i = 16; i < columns; i++)
	{
		temp[0][i] = ' ';
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp[i][j] = borders;
			temp[i][j+14] = borders;
		}
	}
	for (int i = 5; i < 9; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp[i][j] = ' ';
			temp[i][j + 2] = borders;
			temp[i][j + 16] = borders;
		}
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = 16; j < columns; j++)
		{
			temp[i][j] = ' ';
		}
	}
	for (int i = 5; i < 9; i++)
	{
		for (int j = 18; j < columns; j++)
		{
			temp[i][j] = ' ';
		}
	}
	for (int i = 0; i < columns; i++)
	{
		temp[9][i] = ' ';
	}
	for (int i = 2; i < 14 ; i++)
	{
		temp[1][i] = ' ';
	}
	for (int i = 2; i < 4; i++)
	{
		for (int j = 2; j < 4; j++)
		{
			temp[i][j] = ' ';
			temp[i][j + 10] = ' ';
		}
	}
	temp[2][4] = borders;
	temp[2][5] = borders;
	temp[2][6] = leftsidebox;
	temp[2][7] = rightsidebox;
	temp[2][8] = leftsidebox;
	temp[2][9] = rightsidebox;
	temp[2][10] = ' ';
	temp[2][11] = ' ';
	for (int i = 4; i < 10; i += 2)
	{
		temp[3][i] = '>';
		temp[3][i + 1] = '<';
		temp[4][i] = '>';
		temp[4][i + 1] = '<';

	}
	temp[3][10] = borders;
	temp[3][11] = borders;
	temp[4][2] = borders;
	temp[4][3] = borders;
	temp[4][10] = leftsidebox;
	temp[4][11] = rightsidebox;
	temp[4][12] = ' ';
	temp[4][13] = ' ';
	temp[4][16] = borders;
	temp[4][17] = borders;
	temp[5][4] = ' ';
	temp[5][5] = ' ';	
	for (int i = 6; i < 10; i++)
	{
		temp[5][i] = borders;
	}
	temp[5][10] = ' ';
	temp[5][11] = ' ';
	temp[5][12] = leftsidebox;
	temp[5][13] = rightsidebox;
	temp[5][14] = ' ';
	temp[5][15] = ' ';
	temp[6][4] = leftsidebox;
	temp[6][5] = rightsidebox;
	for (int i = 6; i < 10; i++)
	{
		temp[6][i] = ' ';
	}
	temp[6][10] = leftsidebox;
	temp[6][11] = rightsidebox;
	for (int i = 12; i < 16; i++)
	{
		temp[6][i] = ' ';
	}
	for (int i = 4; i < 8; i++)
	{
		temp[7][i] = ' ';
	}
	temp[7][8] = borders;
	temp[7][9] = borders;
	for (int i = 10; i < 14; i++)
	{
		temp[7][i] = ' ';
	}
	temp[7][14] = '<';
	temp[7][15] = loader;
	for (int i = 2; i < columns - 2; i++)
	{
		temp[8][i] = borders;
	}
	return temp;
}
char** Delete(char** level, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]level[i];
	}
	delete[] level;
	return nullptr;
}