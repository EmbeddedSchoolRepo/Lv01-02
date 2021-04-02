#include <stdio.h>


float func(float a,float b,float c)
{
	
	return a+b+c;
}	


int main(void)
{
	float num1, num2, num3, res;


	num1 = 2.33f;
	num2 = 1.15f;
	num3 = 2.57f;
	
	res = func(num1,num2,num3);

	printf("세가지 소수 합은 : %f\n", res);

	return 0;
}
