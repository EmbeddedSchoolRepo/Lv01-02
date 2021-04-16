#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{   
	int player[3] = {0};
	int player1_dice[1] = {0};
	int player2_dice[1] = {0};
	int player3_dice[1] = {0};
	int max;
	
	int x;
	for(x=0; x < 2; x++)
	{
	
    player[0] = (rand() % 6) + 1;
 
    while (1)//중복방지
    {
        player[1] = (rand() % 6) + 1;
        if (player[1] != player[0])
            break;
    }
 
    while (1)//중복방지
    {
        player[2] = (rand() % 6) + 1;
        if (player[2] != player[0] && player[2] != player[1])
            break;
    }
    
    player1_dice[1] = player1_dice[0];
    player1_dice[0] = player[0];
    player2_dice[1] = player2_dice[0];
    player2_dice[0] = player[1];
    player3_dice[1] = player3_dice[0];
    player3_dice[0] = player[2];
    
	if(player1_dice[0] % 2 == 1 || player2_dice[0] % 2 == 1 || player3_dice[0] % 2 ==1)
    {
		printf(" : %d\n", player1_dice[0]);	
		printf(" : %d\n", player2_dice[0]);
		printf(" : %d\n", player3_dice[0]);
		
    	if(max < player1_dice[0])
			max = player1_dice[0];
		if(max < player2_dice[0])
			max = player2_dice[0];	
		if(max < player3_dice[0])
			max = player3_dice[0];
		
		printf("1개의 주사위 높은 숫자 : %d\n", max);
	}
	
	if(player1_dice[0] % 2 == 0 || player2_dice[0] % 2 == 0 || player3_dice[0] % 2 == 0)
	{
		if(player1_dice[0] == 1)
		{
			goto one;
		}
		else if(player1_dice[0] == 3)
		{
			goto three;
		}	
		else if(player1_dice[0] == 4)
		{
			goto four;
		}	
		else if(player1_dice[0] == 6)
		{
			goto six;
		}
	}
	}
 
	return 1;
	 
	one:
		scanf("%d\n", &find);
		scanf("%d\n", &find);
	three:
		 
	four:
		return 0; //종료  
	six:
		for(x = 0; x < )
}
