#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int dice;
	srand(time(NULL));

	dice = rand() % 6 + 1;

	printf("%d\n", dice);

	return 0;
}
