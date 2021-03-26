#include <stdio.h>

int main(void)
{
	int num1, num2;

	printf("두 개의 정수를 입력하세요 : ");
	scanf("%d %d", &num1, &num2);

	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);

	if(num1 > num2)
	{
		printf("num1(%d)가 num2(%d) 보다 큽니다. \n", num1, num2);
	}
	else if(num1 < num2)
	{
		printf("num2(%d)가 num1(%d) 보다 큽니다. \n", num2, num1);
	}
	else
	{
		printf("num1(%d)와 num2(%d)는 서로 같습니다. \n", num1, num2);
	}
	
	return 0;
	
}
