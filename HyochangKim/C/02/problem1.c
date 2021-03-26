#include <stdio.h>

int main(void)
{
	int num1;
	for(num1 = 0; num1 <= 100; num1++)
	{
		if(!(num1 % 2 == 0))
		{
			printf("%3d", num1);
		}
	
		else if(num1 % 20 == 0)
		{
			puts("");
		}
	}
	return 0;
}
