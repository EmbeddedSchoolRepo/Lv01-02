#include <stdio.h>
#include <time.h>

void make_random_numbers(int *numbers, int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		numbers[i] = rand() % 10 + 1;
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
	int numbers[30] = { 0 };
	int len = sizeof(numbers) / sizeof(int);

	srand(time(NULL));

	make_random_numbers(numbers, len);
	
	print_random_numbers(numbers, len);

	return 0;
}
