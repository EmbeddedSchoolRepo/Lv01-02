#include <stdio.h>

int main(void)
{
	int num_a, num_b, res, div;

	printf("원하는 숫자를 입력하세요: ");

	scanf("%d", &num_a);

	printf("배수단위로 정렬하고자 하는 범위를 입력하세요: ");

	scanf("%d", &num_b);

	res = num_a & ~(num_b - 1);
	printf("res = %d\n", res);

	div = res / num_b;
	printf("res(%d) / num_b(%d) = div(%d)\n", res, num_b, div);
	printf("div(%d) * num_b(%d) = res(%d)\n", div, num_b, div * num_b);

	return 0;
}
