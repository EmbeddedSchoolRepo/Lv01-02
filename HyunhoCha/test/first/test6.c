#include <stdio.h>

int find_number(int num1, int num2, int num3)
{
	int i;
	int n1 = num1;
	int n2 = num2;
	int n3 = num3;

	int number = 0;

	for (i = 1; i <= 17; i++)
	{
		if(i % 2 == 0)
		{
			number = n3 + (n1 * -1);
		}

		else
		{
			number = n3 + n1;
		}
		
		n1 = n2;
		n2 = n3;
		n3 = number;
	}

	return number;
}

int main(void)
{
	int num1 = 1;
	int num2 = 6;
	int num3 = 2;
	
	int number = 0;

	number = find_number(num1, num2, num3);
	
	printf("20번째 숫자는 : %d\n", number);

	return 0;
}
