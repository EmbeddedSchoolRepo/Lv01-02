#include <stdio.h>

int main(void)
{
	short num1;
	int sum_two = 0, sum_three = 0;
	for(num1 = 1; num1 <= 100; num1++)
	{
		if(num1 % 2 == 0)
		{
			sum_two += num1;
		}
		else if(num1 % 3 == 0)
		{
			sum_three += num1;
		}
	}
	printf("2의 배수 total : %d\n", sum_two);
	printf("3의 배수 total : %d\n", sum_three);
	return 0;
}

