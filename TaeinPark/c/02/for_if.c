#include <stdio.h>

int main(void)
{
	int i;

	for(i=0;i<20;i++)
	{
		if(!(i%2))
		{
			printf("%d ",i);
		}
	}
	printf("\n");

	return 0;
}

