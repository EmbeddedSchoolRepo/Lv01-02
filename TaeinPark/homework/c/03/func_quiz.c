#include <stdio.h>

float my_func(float a, float b, float c)
{
	return a + b + c;
}

int main(void)
{
	float num1 = 3.3f, num2 = 3.7f, num3 = 5.6f, res;

	res = my_func(num1, num2, num3);

	printf("res = %.8f\n", res);

	return 0;
}

