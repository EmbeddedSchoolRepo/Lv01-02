#include <stdio.h>
#include <time.h>
#include <stdbool.h>


#define START_SALARY_MIN	3000
#define START_SALARY_MAX	3500

#define INCREASE_RATE_MAX	10
#define INCREASE_RATE_MIN	1

#define YEAR	10

bool init_salary(int *employee, int len)
{
	int i;
	
	if (employee == NULL)
	{
		return false;
	}

	for (i = 0; i < len; i++)
	{
		employee[i] = START_SALARY_MIN + (rand() % ((START_SALARY_MAX - START_SALARY_MIN) + 1));
	}

	return true;
}

bool print_salary_avg(int *employee, int len)
{
	int i,j,k;
	float increase_rate;
	float avg = 0.0f;
	float variance = 0.0f;

	if(employee == NULL)
	{
		return false;
	}

	for (i = 0; i < YEAR; i++)
	{
		avg = 0.0f;
		for (j = 0; j < len; j++)
		{
			increase_rate = (float) ((rand() % INCREASE_RATE_MAX) + INCREASE_RATE_MIN) / 100;
			employee[j] = employee[j] + (employee[j] * increase_rate);
			avg += (float)employee[j];
			
		}
		avg = avg / 5.0
		
		printf("%d년차 평균 : %.3f\n", i + 1, avg);
	}


	return true;
}

		


int main(void)
{
	int employee[5] = { 0 };
	int employee_number = sizeof(employee) / sizeof(int);
	int max_index = 0;

	srand(time(NULL));

	if (init_salary(employee, employee_number) == false)
	{
		return -1;
	}

	if (print_salary_avg(employee, employee_number) == false)
	{
		return -1;
	}




	return 0;
}
