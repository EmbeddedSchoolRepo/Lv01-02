// f(x) = x^2의 대한 정적분 구하는 프로그램 작성.

#include <stdio.h>

float integral(float a, float b, float n)
{
	int i;
	float fx;
	float area;
	float dx=(b-a)/n;
	float integral = 0;
	float x=a;

	for(i=1; i<=n; i++)
	{
		fx = x*x;
		area = dx * fx;
	        integral += area;
		x = x+dx;
		//printf("%.3f",dx);
	}
	return integral;
}

int main(void)
{
	int a,b,n;
	float res;

	printf("시작 값 a를 적어 주세요 : ");
	scanf("%d", &a);

	printf("끝 값 b를 적어 주세요 : ");
	scanf("%d", &b);

	printf("적분 구간 [%d, %d]의 등분수 n을 적어 주세요 : ",a,b);
	scanf("%d", &n);

	res = integral(a,b,n);

	printf("f(x) = x^2의 적분 구간 [%d, %d]의 적분 근사치는 %.3f 입니다. \n",a,b,res);

	return 0;
}

