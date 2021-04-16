#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int i, sum, res;
	int x, y, z;
	
	while(1)
	{
		x = rand() % 6 + 1;
		y = rand() % 6 + 1;
		z = rand() % 6 + 1;
		
		sum = x + y + z;
				
		if(res < sum)
			res = sum;
			
			
		printf("res : %d\n", res);
	}
	return 0;
}
