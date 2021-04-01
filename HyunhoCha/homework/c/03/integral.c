#include <stdio.h>

double integral_method1(const int a, const int b, double (*fx)(double x), int resolution);
double integral_method2(const int a, const int b, double (*fx)(double x), int resolution);

double function1(double x)
{
	return x * x;
}

int main(void)
{
	int a = 0;
	int b = 3;
	double result = 0.0;

	result = integral_method1(0, 3, function1, 4096);	

	printf("integral x^2 : %lf \n", result);

	result = integral_method2(0, 3, function1, 4096);	
	printf("integral x^2 : %lf \n", result);
	return 0;
}

double integral_method1(const int a, const int b, double (*f)(double x), int resolution)
{
	double result, deltaX;
	int i;
	deltaX = (b - a) / (double) resolution;

	for(i = 0; i < resolution; i++)
	{
		result += f((a + deltaX / 2) + (i * deltaX)) * deltaX;
	}

	return result;
}
	
double integral_method2(const int a, const int b, double (*f)(double x), int resolution)
{
	double result, deltaX;
	int i;
	deltaX = (b - a) / (double) resolution;

	for(i = 0; i < resolution; i++)
	{
		result += (f(a + deltaX * i) + f(a + deltaX * (i+1))) /2 * deltaX;
	}

	return result;
}	
