#include <stdio.h>
#include <stdlib.h>

#define player 3

int main(void) {
	int i, sum, res;
	int dice1, dice2;
	
	
	for(i = 0; i < player; i++)
	{
		dice1 = rand() % 6 + 1;
		dice2 = rand() % 6 + 1;
		
		sum = dice1 + dice2;
				
		if(res < sum)
			res = sum;
			
			
		printf("res : %d\n", res);
	}
	return 0;
}
