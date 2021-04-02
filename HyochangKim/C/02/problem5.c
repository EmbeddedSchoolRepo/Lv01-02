#include <stdio.h>

int main(void)
{
	int num1;
	int f0 = 1, f1 = 1, sum;
	for(num1 = 1; num1 <= 25; num1++)
	{
		sum = f0 + f1;
		f0 = f1;
		f1 = sum;
	}
	printf("%d\n", f0);
	return 0;
}

