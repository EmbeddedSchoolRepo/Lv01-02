#include<stdio.h>
int bit(int a, int b);


int bit_and(int a, int b)
{
	return a * b;
}


int main(void)
{
	int num1 = 2 , num2 = 8 , bitand, r;

	bitand = bit_and(num1, num2);


	printf("bit_and 의 결과 : %d\n",bitand);

	return 0;
}
