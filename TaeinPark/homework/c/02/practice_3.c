#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;

	// 1 ~ 33 까지의 숫자를 i 에 대입
	for(i=1;i<=33;i++)
	{
		// 3의 배수 일 때 if 문 진입
		if(!(i%3))
		{
			// 진입한 3의 배수를 sum에 합산
			sum += i;
		}
	}
	printf("1 ~ 33 까지의 숫자 중 3의 배수의 합은 %d 입니다. \n", sum);

	return 0;
}


