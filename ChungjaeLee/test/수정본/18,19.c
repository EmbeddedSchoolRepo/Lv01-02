#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void setting_pay(double* pay)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		pay[i] = 3000 + 100 * (rand() % 6); 
	}
	printf("\n");
}	

double setting_inc_rate(void)
{
	double r = 0.01 * (rand() % 10 + 1);
	return r;
}

void print_pay(double* pay)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("사원%d:%.2f만원  ", i + 1, pay[i]);
	}
	printf("\n\n");
}

void aftersalary(double* pay, int n)
{
	int i, j;
	double r;
	
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < n; j++)
		{
			r = setting_inc_rate();
			pay[i] = pay[i] * (1 + r);
		}
	}
}

void findMX(double* pay, double* comp, int* name)
{
	int i;

	comp[0] = pay[0];

	for(i = 0; i < 4; i++)
	{
		if(comp[i] > pay[i+1])
		{
			comp[i+1] = comp[i];
			name[i+1] = name[i];
		}
		else
		{
			comp[i+1] = pay[i+1];
		}
	}
		printf("사원%d: %.2f\n\n", name[4], comp[4]);	
}

double cal_avg(double* pay)
{
	int i;
	double avg;
	double sum = 0;

	for(i = 0; i < 5; i++)
	{
		sum += pay[i];
	}

	avg = sum / 5;

	return avg;
}

void cal_dev(double* pay)
{
	int i;
	double avg = cal_avg(pay);
	double sum = 0;
	double dif, square, var, dev;

	for(i = 0; i < 5; i++)
	{

		dif = pay[i] - avg;
		square = pow(dif, 2);
		sum += square; 
	}

	var = sum / 5;
	dev = sqrt(var); 

	printf("표준편차값은 %.2f입니다.\n", dev);
}

int main(void)
{
	int i, n;
	double pay[5];
	double comp[5];
	int name[5] = {1, 2, 3, 4, 5};

	srand(time(NULL));
	
	setting_pay(pay);

	printf("신입사원 초봉\n");
	print_pay(pay);
	
	printf("몇년후 연봉이 알고싶으싶니까? ");
	scanf("%d", &n);
	
	aftersalary(pay, n);
	printf("%d년후 연봉\n", n);
	print_pay(pay);

	printf("최고연봉 금액은?\n");
	findMX(pay, comp, name);

	printf("연봉 평균값은? ");
	double avg = cal_avg(pay);
	printf("%.2f\n", avg);

	cal_dev(pay);
	return 0;
}
