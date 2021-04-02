#include <stdio.h>

//2의 배수의 합
int multi_two(void)
{
	int i;
	int sum_2;

	for(i=1; i<=100; i++)
	{
		if(!(i%2))
		{
			sum_2 += i;
		}
	}
	return sum_2;
}

//3의 배수의 합
int multi_three(void)
{
	int i;
	int sum_3;

	for(i=1; i<=100; i++)
	{
		if(!(i%3))
		{
			sum_3 += i;
		}
	}
	return sum_3;
}

int main(void)
{
	int res_2, res_3;

	res_2 = multi_two();
	res_3 = multi_three();

	printf("1 ~ 100 까지의 숫자 중 2의 배수의 합은 %d 입니다. \n", res_2);
	printf("1 ~ 100 까지의 숫자 중 3의 배수의 합은 %d 입니다. \n", res_3);

	return 0;
}

