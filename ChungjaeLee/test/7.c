#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void random_max10(void)
{
	int R;
	R = rand() % 10 + 1;
	printf("%d\n", R);
}

int main(void)
{
	int i;
	srand(time(NULL));

	for(i = 0; i < 30; i++)
	{
		random_max10();
	}

	return 0;
}
