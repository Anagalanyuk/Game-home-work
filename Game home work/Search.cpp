bool Finish( char** level, char** restart, int rows, int columns, char leftsidebox)
{
	int result = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (restart[i][j] == '>')
			{
				result++;
				if (level[i][j] == leftsidebox)
				{
					result--;
				}
			}
		}
	}
	return result;
}