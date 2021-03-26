#include <stdio.h>

int main(void)
{
	short num1;
	int sum = 0;

	for(num1=1; num1 <= 33; num1++)
	{
		if(num1%3 == 0)
		{
			printf("3의 배수 : %d\n", sum);
			sum += num1;
		}
	}
	printf("3의 배수 total : %d\n", sum);
	return 0;
}
