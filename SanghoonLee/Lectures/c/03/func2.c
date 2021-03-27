#include <stdio.h>

// f = g(x, y) ===> 입력이 두 개인 함수
int my_func(int a, int b)
{
	return a + b;
}

int main(void)
{
	int num1 = 3, num2 = 7, res;

	// 함수 이름을 통해 함수를 실질적으로 호출 <<<
	// res = num1 + num2;
	res = my_func(num1, num2);

	printf("res = %d\n", res);

	return 0;
}
