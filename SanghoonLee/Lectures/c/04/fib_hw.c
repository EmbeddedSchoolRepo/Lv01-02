#include <stdio.h>

int fib(int num)
{
	int first, second, res = 0;

	if(num <= 0)
	{
		printf("잘못된 입력입니다!\n");
		return -1;
	}
	else if(num < 3)
	{
		return 1;
	}

	// 초항 2개를 알고 시작하기 때문에
	num -= 2;

	first = 1;
	second = 1;

	// C언어에서는 0은 무조건 거짓(false)
	// 0이 아닌 다른 숫자는 ? 참(true)

	// --가 앞에 오는 경우와 뒤에 오는 경우의 차이가 있음
	// --가 앞에 오면 해당 라인에서 연산을 처리하고
	// --가 뒤에 오면 해당 라인 다음에 연산이 처리됨
	while(num--)
	{
		res = first + second;
		first = second;
		second = res;
	}

	return res;
}

int main(void)
{
	int res, num;

	printf("찾고 싶은 피보나치 수열의 항을 입력하세요: ");
	scanf("%d", &num);

	res = fib(num);

	if(res != -1)
	{
		printf("res = %d\n", res);
	}

	return 0;
}
