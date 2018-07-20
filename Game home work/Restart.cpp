#include "Restart.h"

char ** Restart(char ** level, char ** restart, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			level[i][j] = restart[i][j];
		}
	}
	return level;
}