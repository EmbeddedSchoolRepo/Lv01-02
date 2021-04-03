#include<stdio.h>
int bit_or(int a, int b)
{
	return a | b;
}
int main(void) {
	int num_a =20;
	int num_b =14;
	int res;


	printf("%d + %d 는 = %d\n", num_a, num_b, bit_or(num_a, num_b));
	return 0;
}
