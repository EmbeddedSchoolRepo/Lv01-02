#include <stdio.h>

#define BLDC	1
#define SERVO	2
#define CAMERA	3
#define AUDIO	4

int main(void)
{
	int num;

	printf("숫자를 입력 하세요 : ");
	scanf("%d", &num);
	
	switch(num)
	{
		case BLDC:
			printf("BLDC 모터 동작\n");
			break;
		case
		
