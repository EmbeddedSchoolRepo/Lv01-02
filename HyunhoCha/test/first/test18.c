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

bool increas_salary(int *employee, int len)
{
	int i,j;
	float increase_rate;

	if(employee == NULL)
	{
		return false;
	}

	for (i = 0; i < YEAR; i++)
	{
		for (j = 0; j < len; j++)
		{
			increase_rate = (float) ((rand() % INCREASE_RATE_MAX) + INCREASE_RATE_MIN) / 100;
			employee[j] = employee[j] + (employee[j] * increase_rate);
		}
	}

	return true;
}

int find_top_salary(int *employee, int len)
{
	int i;
	int max = 0;
	int max_index = 0;

	if (employee == NULL)
	{
		return -1;
	}
	
	for (i = 0; i < len; i++)
	{
		if (max < employee[i])
		{
			max = employee[i];
			max_index = i;
		}
	}	

	return max_index;
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

	if (increas_salary(employee, employee_number) == false)
	{
		return -1;
	}

	max_index = find_top_salary(employee, employee_number);

	if (max_index == -1)
	{
		return -1;
	}

	printf("10년후 연봉이 가장 높은 사람은 : 사원%d(연봉 : %d)\n", max_index + 1, employee[max_index]);

	return 0;
}
