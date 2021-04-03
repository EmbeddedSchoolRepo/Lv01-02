#include <stdio.h>

int my_func(int num)
{
	return num >> 1;
}

int main(void)
{
	int num = 3, res;

	res = my_func(num);

	printf("res = %d\n", res);

	return 0;
}
