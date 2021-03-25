#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;

	// i 변수는 1 ~ 50 까지의 값을 순차적으로 넣게 된다.
	// sum += i;는 sum = sum + i 가 되므로
	// sum = 0(sum의 초기 값) + 1 => sum : 1
	// sum = 1(sum의 이전 값) + 2 => sum : 3
	// sum = 3(sum의 이전 값) + 3 => sum : 6
	// 이런식으로 50 까지의 합을 sum에 축적하게 된다.
	
	for(i=1; i<=50; i++)
	{
		sum += i;
	}
	printf("1에서 50까지의 합은 %d 입니다. \n", sum);

	return 0;
}
