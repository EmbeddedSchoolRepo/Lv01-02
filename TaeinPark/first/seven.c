#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, random;
//	int num[10] = {1,2,3,4,5,6,7,8,9,10}
//	srand(time(NULL));
	

	for(i=0; i<=30; i++)
	{
		
	        srand(time(NULL));
		random = rand() % 10;
		printf("%d ",random);
	}

	return 0;
}
