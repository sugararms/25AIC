#include <stdio.h>

int main()
{

	int chess[10][10];

	int i = 0;
	int j = 0;
	for (j = 0; j < 10; j = j + 1)
	{
		for (i = 0; i < 10; i++)
		{
			chess[i][j] = i + j;
			printf("\t%d", *(*(chess+i)+j));
		}
		printf("\n");
	}
}