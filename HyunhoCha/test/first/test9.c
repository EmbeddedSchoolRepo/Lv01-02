#include <stdio.h>
#include <time.h>

void dice_game()
{
	int number = rand() % 6 + 1;

	printf("주사위 결과 : %d \n", number);
}

void ext_game(char *ext)
{
	printf("종료(c) : ");
	scanf("%s", ext);
}

int main(void)
{
	char ext = 0;

	while(ext != 'c')	
	{
		dice_game();		
		ext_game(&ext);	
	}

	return 0;
}
