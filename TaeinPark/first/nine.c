#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, random;
	
		
	srand(time(NULL));
	random = (rand() % 6)+1;
	printf("%d\n",random);
	

	return 0;
}
