#include<iostream>

using namespace std;

char** StepLeft(char** level, int key,const int const rows, const int const columns, char loader, char borders, char leftsidebox, char rightsidebox)
{	
	char temp[2] = {};
	int index = 0;
	int index1 = 0;
	for (int  i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (level[i][j] == loader)
			{
				index = i;
				index1 = j;
			}
		}
	}
	if (level[index][index1 - 2] != borders )
	{
        if (level[index][index1 - 2] != rightsidebox || level[index][index1 - 4] != rightsidebox)
		{
			if (level[index][index1 - 2] != rightsidebox || level[index][index1 - 4] != borders)
			{
				if (level[index][index1 - 2] == rightsidebox && level[index][index1 - 4] != borders)
				{
					level[index][index1 - 5] = leftsidebox;
					level[index][index1 - 4] = rightsidebox;
					level[index][index1 - 3] = ' ';
					level[index][index1 - 2] = ' ';
				}
				if (level[index][index1 - 2] == '<')
				{
					level[index][index1 - 3] = ' ';
					level[index][index1 - 2] = ' ';
				}
				temp[0] = level[index][index1];
				temp[1] = level[index][index1 - 1];
				level[index][index1] = level[index][index1 - 2];
				level[index][index1 - 1] = level[index][index1 - 3];
				level[index][index1 - 3] = temp[1];
				level[index][index1 - 2] = temp[0];
				}
			}
		}
	//////////////////////////////////////////////////////////////////////////////////////////
	//if (level[index][index1 - 2] != borders )
	//{
	//	if (level[index][index1 - 2] == rightsidebox && level[index][index1 - 4] == rightsidebox)
	//	{
	//		temp = level;
	//	}
	//	else
	//	{
	//		if (level[index][index1 - 2] == rightsidebox && level[index][index1 - 4] == borders)
	//		{
	//			temp = level;
	//		}
	//		else
	//		{
	//			if (level[index][index1 - 2] == rightsidebox && level[index][index1 - 4] != borders)
	//			{
	//				level[index][index1 - 5] = leftsidebox;
	//				level[index][index1 - 4] = rightsidebox;
	//				level[index][index1 - 3] = ' ';
	//				level[index][index1 - 2] = ' ';
	//			}
	//			if (level[index][index1 - 2] == '<')
	//			{
	//				level[index][index1 - 3] = ' ';
	//				level[index][index1 - 2] = ' ';
	//			}
	//			for (int i = 0; i < index; i++)
	//			{
	//				for (int j = 0; j < columns; j++)
	//				{
	//					temp[i][j] = level[i][j];
	//				}
	//			}

	//			for (int i = 0; i < index1 - 3; i++)
	//			{
	//				temp[index][i] = level[index][i];
	//			}
	//			temp[index][index1 - 3] = level[index][index1 - 1];
	//			temp[index][index1 - 2] = level[index][index1];
	//			temp[index][index1 - 1] = level[index][index1 - 2];
	//			temp[index][index1] = level[index][index1 - 3];
	//			for (int j = index1 + 1; j < columns; j++)
	//			{
	//				temp[index][j] = level[index][j];
	//			}
	//			for (int i = index + 1; i < rows; i++)
	//			{
	//				for (int j = 0; j < columns; j++)
	//				{
	//					temp[i][j] = level[i][j];
	//				}
	//			}
	//			level = temp;
	//		}
	//	}
	return level;
}
char** StepRight(char** level, int key, const int const rows, const int const columns, char loader, char borders, char leftsidebox, char rightsidebox)
{		
	int index = 0;
	int index1 = 0;
	char temp[2] = {};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (level[i][j] == loader)
			{
				index = i;
				index1 = j;
			}
		}
	}
		if (level[index][index1 + 1] != borders)
	     {
		   if (level[index][index1 + 1] != leftsidebox || level[index][index1 + 3] != borders)
		      {
			    if (level[index][index1 + 1] != leftsidebox || level[index][index1 + 3] != leftsidebox)
			        {
				if (level[index][index1 + 1] == leftsidebox && level[index][index1 + 3] != borders)
				{
					level[index][index1 + 3] = leftsidebox;
					level[index][index1 + 4] = rightsidebox;
					level[index][index1 + 1] = ' ';
					level[index][index1 + 2] = ' ';
				}
				if (level[index][index1 + 1] == '>')
				{
					level[index][index1 + 1] = ' ';
					level[index][index1 + 2] = ' ';
				}
				temp[0] = level[index][index1];
				temp[1] = level[index][index1 - 1];
				level[index][index1] = level[index][index1 + 2];
				level[index][index1 - 1] = level[index][index1 + 1];
				level[index][index1 + 2] = temp[0];
				level[index][index1 + 1] = temp[1];
			}
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////
	//if (level[index][index1 + 1] != borders)
	//{
	//char** temp = new char*[rows];
	//	for (int i = 0; i < rows; i++)
	//	{
	//		temp[i] = new char[columns];
	//	}

	//	if (level[index][index1 + 1] == leftsidebox && level[index][index1 + 3] == borders)
	//	{
	//		temp = level;
	//	}
	//	else
	//	{
	//		if (level[index][index1 + 1] == leftsidebox && level[index][index1 + 3] == leftsidebox)
	//		{
	//			temp = level;
	//		}
	//		else
	//		{
	//			if (level[index][index1 + 1] == leftsidebox && level[index][index1 + 3] != borders)
	//			{
	//				level[index][index1 + 3] = leftsidebox;
	//				level[index][index1 + 4] = rightsidebox;
	//				level[index][index1 + 1] = ' ';
	//				level[index][index1 + 2] = ' ';
	//			}
	//			if (level[index][index1 + 1] == '>')
	//			{
	//				level[index][index1 + 1] = ' ';
	//				level[index][index1 + 2] = ' ';
	//			}
	//			for (int i = 0; i < index; i++)
	//			{
	//				for (int j = 0; j < columns; j++)
	//				{
	//					temp[i][j] = level[i][j];
	//				}
	//			}
	//			for (int i = 0; i < index1 - 1; i++)
	//			{
	//				temp[index][i] = level[index][i];
	//			}
	//			temp[index][index1 - 1] = level[index][index1 + 1];
	//			temp[index][index1] = level[index][index1 + 2];
	//			temp[index][index1 + 2] = level[index][index1];
	//			temp[index][index1 + 1] = level[index][index1 - 1];
	//			for (int j = index1 + 3; j < columns; j++)
	//			{
	//				temp[index][j] = level[index][j];
	//			}
	//			for (int i = index + 1; i < rows; i++)
	//			{
	//				for (int j = 0; j < columns; j++)
	//				{
	//					temp[i][j] = level[i][j];
	//				}
	//			}
	//			level = temp;
	//		}
	//	}
	//}
//////////////////////////////////////////////////////////////////////////////////////////
	return level;
}
char** StepUp(char** level, int key, const int const rows, const int const columns, char loader, char borders, char rightsidebox)
{
	int index = 0;
	int index1 = 0;
	char temp[2] = {};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (level[i][j] == loader)
			{
				index = i;
				index1 = j;
			}
		}
	}
	if (level[index - 1][index1] != borders)
	{
	  if (level[index - 1][index1] != rightsidebox || level[index - 2][index1] != rightsidebox)
		{
		  if (level[index - 1][index1] != rightsidebox || level[index - 2][index1] != borders)
			{
			  if (level[index - 1][index1] == rightsidebox && level[index - 2][index1] != borders)
				{
					level[index - 2][index1] = level[index - 1][index1];
					level[index - 2][index1 - 1] = level[index - 1][index1 - 1];
					level[index - 1][index1] = ' ';
					level[index - 1][index1 - 1] = ' ';
				}
				if (level[index - 1][index1] == '<')
				{
					level[index - 1][index1] = ' ';
					level[index - 1][index1 - 1] = ' ';
				}
				temp[0] = level[index][index1];
				temp[1] = level[index][index1 - 1];
				level[index][index1] = level[index - 1][index1];
				level[index][index1 - 1] = level[index - 1][index1 - 1];
				level[index - 1][index1] = temp[0];
				level[index - 1][index1 - 1] = temp[1];
			}
		}
	}
	/*if (level[index - 1][index1] != borders )
	{
		if (level[index - 1][index1] == rightsidebox && level[index - 2][index1] == rightsidebox)
		{
			temp = level;
		}
		else
		{
			if (level[index - 1][index1] == rightsidebox && level[index - 2][index1] == borders)
			{
				temp = level;
			}
			else
			{
				if (level[index - 1][index1] == rightsidebox && level[index - 2][index1] != borders)
				{
					level[index - 2][index1] = level[index - 1][index1];
					level[index - 2][index1 - 1] = level[index - 1][index1 - 1];
					level[index - 1][index1] = ' ';
					level[index - 1][index1 - 1] = ' ';
				}
				if (level[index - 1][index1] == '<')
				{
					level[index - 1][index1] = ' ';
					level[index - 1][index1 - 1] = ' ';
				}


				for (int i = 0; i < index - 1; i++)
				{
					for (int j = 0; j < columns; j++)
					{
						temp[i][j] = level[i][j];
					}
				}
				for (int i = 0; i < index1 - 1; i++)
				{
					temp[index - 1][i] = level[index - 1][i];
				}

				temp[index - 1][index1 - 1] = level[index][index1 - 1];
				temp[index - 1][index1] = level[index][index1];

				for (int i = index1 + 1; i < columns; i++)
				{
					temp[index - 1][i] = level[index - 1][i];
				}
				for (int i = 0; i < index1 - 1; i++)
				{
					temp[index][i] = level[index][i];
				}
				temp[index][index1 - 1] = level[index - 1][index1 - 1];
				temp[index][index1] = level[index - 1][index1];
				for (int j = index1 + 1; j < columns; j++)
				{
					temp[index][j] = level[index][j];
				}
				for (int i = index + 1; i < rows; i++)
				{
					for (int j = 0; j < columns; j++)
					{
						temp[i][j] = level[i][j];
					}
				}

				level = temp;
			}
		}
	}*/
	return level;
}

char** StepDown(char** level, int key, const int const rows, const int const columns, char loader, char borders, char rightsidebox)
{
	
		int index = 0;
		int index1 = 0;

		char temp[2] = {};
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (level[i][j] == loader)
				{
					index = i;
					index1 = j;
				}
			}
		}
		if (level[index + 1][index1] != borders)
		{
		  if (level[index + 1][index1] != rightsidebox || level[index + 2][index1] != rightsidebox)
			{
			  if (level[index + 1][index1] != rightsidebox || level[index + 2][index1] != borders)
			  {
				if (level[index + 1][index1] == rightsidebox && level[index + 2][index1] != borders)
					{
						level[index + 2][index1] = level[index + 1][index1];
						level[index + 2][index1 - 1] = level[index + 1][index1 - 1];
						level[index + 1][index1] = ' ';
						level[index + 1][index1 - 1] = ' ';
					}
					if (level[index + 1][index1] == '<')
					{
						level[index + 1][index1] = ' ';
						level[index + 1][index1 - 1] = ' ';
					}
					temp[0] = level[index][index1];
					temp[1] = level[index][index1 - 1];
					level[index][index1] = level[index + 1][index1];
					level[index][index1 - 1] = level[index + 1][index1 - 1];
					level[index + 1][index1] = temp[0];
					level[index + 1][index1 - 1] = temp[1];
				}
			}
		}
/////////////////////////////////////////////////////////////////////////////////////
		//if (level[index + 1][index1] != borders)
		//{ 
		//	if (level[index + 1][index1] == rightsidebox && level[index + 2][index1] == rightsidebox)
		//	{
		//		temp = level;
		//	}
		//	else
		//	{
		//		if (level[index + 1][index1] == rightsidebox && level[index + 2][index1] == borders)
		//		{
		//			temp = level;
		//		}
		//		else
		//		{
		//			if (level[index + 1][index1] == rightsidebox && level[index + 2][index1] != borders)
		//			{
		//				level[index + 2][index1] = level[index + 1][index1];
		//				level[index + 2][index1 - 1] = level[index + 1][index1 - 1];
		//				level[index + 1][index1] = ' ';
		//				level[index + 1][index1 - 1] = ' ';
		//			}
		//			if (level[index + 1][index1] == '<')
		//			{
		//				level[index + 1][index1] = ' ';
		//				level[index + 1][index1 - 1] = ' ';
		//			}
		//			for (int i = 0; i < index; i++)
		//			{
		//				for (int j = 0; j < columns; j++)
		//				{
		//					temp[i][j] = level[i][j];
		//				}
		//			}
		//			for (int i = 0; i < index1 - 1; i++)
		//			{
		//				temp[index][i] = level[index][i];
		//			}

		//			temp[index][index1 - 1] = level[index + 1][index1 - 1];
		//			temp[index][index1] = level[index + 1][index1];

		//			for (int i = index1 + 1; i < columns; i++)
		//			{
		//				temp[index][i] = level[index][i];
		//			}
		//			for (int i = 0; i < index1 - 1; i++)
		//			{
		//				temp[index + 1][i] = level[index + 1][i];
		//			}

		//			temp[index + 1][index1 - 1] = level[index][index1 - 1];
		//			temp[index + 1][index1] = level[index][index1];
		//			for (int j = index1 + 1; j < columns; j++)
		//			{
		//				temp[index + 1][j] = level[index + 1][j];
		//			}
		//			for (int i = index + 2; i < rows; i++)
		//			{
		//				for (int j = 0; j < columns; j++)
		//				{
		//					temp[i][j] = level[i][j];
		//				}
		//			}
		//			level = temp;
		//		}
		//	}
		//}
//////////////////////////////////////////////////////////////////////////////////////////////////
		return level;
}

