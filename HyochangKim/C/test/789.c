#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define upper 10
#define lower 1
#define num 30
#define num2 10

void dice_output()
{
	tmp  = (rand() % (upper - lower + 1)) + lower;
}	

int dice_output2(int tmp)
{
	if( res == tmp )
	{
		continue;
	}
	else( res != tmp)
	{
		printf("%3d", res);
	
}

int main()
{
	int res, tmp = 0;
	int a, b;
	
	srand(time(NULL));
	
	printf("숫자 무작위로 1~10 까지 30개 생성\n");
	for(a = 0; a < num;  a++)
	{
		printf("숫자 무작위로 1~10 까지 30개 생성: %d\n", dice_output());
	}
	
	res = tmp;
	tmp = dice_output();
	dice_output2(res, tmp);
	
	for(b = 0; b < num2 b++)
	{
		printf(" 중복되지 않은 숫자 10개 생성: %d\n", dice_output2(res,tmp)):
	}
	

	return 0;
}

