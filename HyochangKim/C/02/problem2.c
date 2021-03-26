#include <stdio.h>

int main(void)
{
	int num1;
	int sum = 0;

	for(num1 = 1; num1 <= 50; num1++)
	{
		sum = sum + num1;
	}
		printf("%d\n", sum);
	return 0;
}

