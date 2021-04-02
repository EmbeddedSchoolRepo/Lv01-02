#include <stdio.h>

int my_plus(void)
{
	int i;
	int sum = 0;
	
	for(i=1; i<=50; i++)
	{
		sum += i;
	}

	return sum;
}

int main(void)
{
	int res;

	res = my_plus();

	printf("1에서 50까지의 합은 %d 입니다. \n", res);

	return 0;
}

