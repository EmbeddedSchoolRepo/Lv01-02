#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int x, dice, max;
	
	
	while(1)
	{
    	dice = rand() % 6 + 1;

    
   		 if(max < dice)
    			max = dice;
    
	}
	printf("높은 주사위 숫자 : %d\n", max);
	return 0;
}
