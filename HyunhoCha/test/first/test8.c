#include <stdio.h>
#include <time.h>

void make_random_numbers(int *numbers, int* number_check, int len)
{
	int i;
	int random;

	for(i = 0; i < len; i++)
	{
		
		random = rand() % 10 + 1;

		while(number_check[random - 1] != 0)
		{
			random = rand() % 10 + 1;
		}

		numbers[i] = random;
		number_check[random - 1] = 1;
	}
}

void print_random_numbers(int *numbers, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		printf("%3d", numbers[i]);
	}

	printf("\n");
}

int main(void)
{
	int numbers[10] = { 0 };
	int number_check[10] = { 0 };
	int len = sizeof(numbers) / sizeof(int);

	srand(time(NULL));

	make_random_numbers(numbers, number_check, len);
	
	print_random_numbers(numbers, len);

	return 0;
}
