#include <stdio.h>

int main(void)
{
	int array[2][2] = {0};
	int i,j;
	int num = 1;

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			array[i][j] = num;
			num++;
		}
	}

	return 0;
}
