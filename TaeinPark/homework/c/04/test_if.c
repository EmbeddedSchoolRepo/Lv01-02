#include <stdio.h>

int main(void)
{
	int num1 = 1, num2 = 2;


	if(num1 > num2)
	{
		printf("num1(%d)가 num2(%d)보다 큽니다.\n", num1, num2);
	}
	else
	{
		printf("num2(%d)가 num1(%d)보다 큽니다.\n", num2, num1);
	}

	return 0;
}

