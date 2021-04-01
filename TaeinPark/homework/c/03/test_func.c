#include <stdio.h>

int my_func(int num)
{
	// 쉬프트 연산자로 비트를전체적으로 1칸 밀어 올림
	// num << 1 은 1칸, num << 2 는 2칸, num << 3 은 3칸
	// 비트의 2^n을 의미하므로 결국 2^n 비트 이동 칸 수 만큼 숫자가 곱해진다.
	
	// num >> 1 은 1칸, num >> 2는 2칸 이동이 동일하다.
	// 그러나 이 방식은 우측 이동이다.
	// 그러므로 나누기와 같은데 주의점은
	// 소수점을 취급하지 않아 0.5 같은건 버린다.
	return num << 1;
}

int main(void)
{
	int num = 3, res;

	res = my_func(num);

	printf("res = %d\n", res);

	return 0;
}

