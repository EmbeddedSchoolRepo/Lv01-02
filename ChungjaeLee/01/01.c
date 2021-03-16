#include <stdio.h>

int main()
{
	int num1 = 1; 
	short num2 = 2;
	char num3 = 3;

	float num4 = 2.3f;
	double num5 = 2.8;

	long long int num6 = 10000000000;
	long double num7 = 2942723.2234;

	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
	printf("num3 = %d\n", num3);

	printf("num4 = %f\n", num4);
	printf("num4 = %.2f\n", num4);
	printf("num5 = %f\n", num5);

	printf("num6 = %lld\n", num6);
	printf("num7 = %Lf\n", num7);

	return 0;
}
