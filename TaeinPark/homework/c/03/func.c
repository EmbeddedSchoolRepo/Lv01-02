#include <stdio.h>

// 리턴 타입 : int
// 함수 이름 : my_func
// 인자 타입 : int

int my_func(int num)
{
	return num + 6;
}

int main(void)
{
	int num1 = 3, res;

	res = my_func(num1);

	printf("res = %d\n", res);

	return 0;
}

