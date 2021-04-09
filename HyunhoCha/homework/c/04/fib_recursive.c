#include <stdio.h>

// recursive_fib(6)   -> 1.recursive_fib(5) + 2.recursive_fib(4)
// 1.recursive_fib(5) -> 1.recursive_fib(4) + 2.recursive_fib(3)
// 1.recursive_fib(4) -> 1.recursive_fib(3) + 2.recursive_fib(2)
// 1.recursive_fib(3) -> 1.recursive_fib(2) + 2.recursive_fib(1)
// 1.recursive_fib(2) -> 1
// 2.recursive_fib(1) -> 1
// 1.recursive_fib(3) -> 2
// 2.recursive_fib(2) -> 1
// 1.recursive_fib(4) -> 3
// 2.recursive_fib(3) -> 3.recursive_fib(2) + 4.recursive_fib(1)
// 3.recursive_fib(2) -> 1
// 4.recursive_fib(1) -> 1
// 1.recursive_fib(5) -> 5
// 2.recursive_fib(4) -> 3.recursive_fib(3) + 4.recursive_fib(2)
// 3.recursive_fib(3) -> 3.recursive_fib(2) + 4.recursive_fib(1)
// 3.recursive_fib(2) -> 1
// 4.recursive_fib(1) -> 1
// 3.recursive_fib(3) -> 2
// 4.recursive_fib(2) -> 1
// 2.recursive_fib(4) -> 3
// recursive_fib(6)   -> 8

/*
main --------------------------------------------------
         6
res     num
recursive_fib(6) --------------------------------------
 6          5
numa      fib(5) + fib(4)
recursive_fib(5) --------------------------------------
 5          3        2
num       fib(4) + fib(3)
recursive_fib(4) --------------------------------------
 4          2        1
num       fib(3) + fib(2)
recursive_fib(3) --------------------------------------
 3          1        1
num       fib(2) + fib(1)
recursive_fib(2) = 1 --------------------------------------
 2                   연산(처리)이 완료된 스택은 x 표시를 쳐서 없앤다.
num
fib(1) = 1 ------------------------------------------------
 1
num
fib(2) = 1 ------------------------------------------------
 2
num
fib(3) ---------------------------------------------------
 3         1        1
num      fib(2) + fib(1)
fib(2) = 1 -----------------------------------------------
 2
num
fib(1) = 1 ----------------------------------------------
 1
num
*/

int recursive_fib(int num)
{
	if(num <= 0)
	{
		printf("올바른 값을 입력하세요!\n");
		return -1;
	}
	else if(num < 3)
	{
		return 1;
	}
	else
	{
		return recursive_fib(num - 1) + recursive_fib(num - 2);
	}
}

int main(void)
{
	int num, res;

	printf("몇 번째 피보나치 항을 구할까요 ? ");
	scanf("%d", &num);

	res = recursive_fib(num);
	printf("res = %d\n", res);

	return 0;
}
