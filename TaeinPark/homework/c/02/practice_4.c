#include <stdio.h>

int main(void)
{
	int i, i_2, i_3;
	int sum_2=0;
	int sum_3=0;

	// 3의 배수의 범위가 더 좁은 조건이기 때문에 2의 배수 보다 더 위에 if문을 배치함
	
	// 1 ~ 100 까지의 숫자를 i 에 대입
	for(i=1;i<=100;i++)
	{
		// 3의 배수 일 때 if 문 진입
		if(!(i%3))
		{
			// 3의 배수의 숫자를 i_3으로 전달
			i_3 = i;
			// i_3에 들어간 3의 배수를 sum_3 으로써 합산
			sum_3 += i_3;
		}
		// 2의 배수 일 때 if 문 진입
		else if(!(i%2))
		{
			// 2의 배수의 숫자를 i_2으로 전달
			i_2 = i;
			// i_2에 들어간 3의 배수를 sum_2으로써 합산
			sum_2 += i_2;
		}
	}
	printf("1 ~ 100 까지의 숫자 중 3의 배수의 합은 %d\n", sum_3);
	printf("1 ~ 100 까지의 숫자 중 2의 배수의 합은 %d\n", sum_2);

	return 0;
}

