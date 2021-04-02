#include<stdio.h>
int bit_not(int a);

int bit_not(int a)
{
	return ~a;
}

int main(void)
{
	int num1 = 50, bitnot;
	bitnot = bit_not(num1);
	printf("bit_not 의 결과 : %d\n",bitnot);
	return 0;
}
