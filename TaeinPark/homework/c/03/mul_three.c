#include <stdio.h>

int multi_three(void)
{
	int i;
	int sum=0;

	for(i=1; i<=33; i++)
	{
		if(!(i%3))
		{
			sum += i;
		}
	}

	return sum;
}

int main(void)
{
	int res;

	res = multi_three();

	printf("1 ~ 33 까지의 숫자 중 3의 배수의 합은 %d 입니다. \n", res);

	return 0;
}

