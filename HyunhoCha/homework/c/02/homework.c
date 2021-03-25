#include <stdio.h>
#include <assert.h>


int problem1(void);
int problem2(void);
int problem3(void);
int problem4(void);
int problem5(void);
int problem6(void);

int problem2_loop(void);
int problem3_loop(void);
int problem4_loop(void);

int printOddNumber(int range);
int continousSum(const int range);
int continousSumLoop(const int range);
int multipleSum(const int range, const int multiple);
int multipleSumLoop(const int range, const int multiple);
int fibonacciNumbers(int index);

int main()
{
	
	assert(problem1() == 1);

	assert(problem2() == 1275);
	assert(problem2_loop() == 1275);

	assert(problem3() == 198);
	assert(problem3_loop() == 198);

	assert(problem4() == 4233);
	assert(problem4_loop() == 4233);

	assert(problem5() == 55);

	assert(problem6() == 5);
	printf("Perfect !! \n");

	return 0;
}


int printOddNumber(int range)
{
	int i;
	int numberCount = 0;

	if (range < 0)
	{
		return 0;
	}
4
	for (i = 0; i < range; i++)
	{
		if (i % 2 == 1)
		{
			printf("%2d ", i);
			numberCount++;
			if (numberCount % 10 == 0)
			{
				printf("\n");
			}
		}
	}

	return 1;
}



int continousSumLoop(const int range)
{
	int result = 0;
	int i;

	if (range <= 0)
	{
		return 0;
	}


	for (i = 1; i <= range; i++)
	{
		result += i;
	}

	return result;
}

int continousSum(const int range)
{
	int result = 0;

	if (range <= 0)
	{
		return 0;
	}

	result = (range * (2 + (range - 1))) / 2;
	
	return result;
}

int multipleSumLoop(const int range, const int multiple)
{
	int result = 0;
	int i;

	if (multiple <= 0 || range <= 0)
	{
		return 0;
	}

	for (int i = 1; i <= range; i++)
	{
		if (i % multiple == 0)
		{
			result += i;
		}
	}


	return result;

}

int multipleSum(const int range, const int multiple)
{
	int divisionQuotient = 0;
	int result = 0;

	if (multiple <= 0 || range <= 0)
	{
		return 0;
	}

	divisionQuotient = range / multiple;

	result = (divisionQuotient * (2 * multiple + (divisionQuotient - 1) * multiple)) / 2;

	return result;
}


int fibonacciNumbers(int index)
{
	int result = 0;
	int number1 = 1;
	int number2 = 1;
	int i;

	if (index <= 0)
	{
		return 0;
	} 
	else if (index <= 2)
	{
		return 1;
	}

	for (i = 3; i <= index; i++)
	{
		result = number1 + number2;
		number1 = number2;
		number2 = result;
4	}	

	return result;
}

int sequenceNumber(int index)
{
	int result = 0;
	int number1 = 1;
	int number2 = 1;
	int number3 = 1;
	int number4 = 1;
4	int i;

	if (index <= 0)
	{
		return 0;
	}
	else if (index <= 4)
	{
		return 1;
	}

	for (i = 5; i <= index; i++)
	{
		result = number1 + number4;
		number1 = number2;
		number2 = number3;
		number3 = number4;
		number4 = result;
	}
	
	return result;
}

int problem1(void)
{
	if (printOddNumber(100) == 0)
	{
		return 0;
	}

	return 1;
}

int problem2_loop(void)
{
	int result = continousSumLoop(50);

	return result;
}

int problem2(void)
{
	int result = continousSum(50);

	return result;
}

int problem3_loop(void)
{
	int result = multipleSumLoop(33, 3);

	return result;
}

int problem3(void)
{
	int result = multipleSum(33, 3);

	return result;
}

int problem4(void)
{
	int result = 0;

	result = multipleSum(100, 2) + multipleSum(100, 3);

	return result;
}

int problem4_loop(void)
{
	int result = 0;

	result = multipleSumLoop(100, 2) + multipleSumLoop(100, 3);

	return result;
}

int problem5(void)
{
	int result = 0;


	result = fibonacciNumbers(10);
	
	return result;
}

int problem6(void)
{
	int result = 0;

	result = sequenceNumber(8);

	return result;
}

