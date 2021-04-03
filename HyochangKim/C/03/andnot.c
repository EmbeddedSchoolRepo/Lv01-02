#include<stdio.h>
int input(void)
{
	int x;
	printf("숫자 입력");
	scanf("%d", &x);

	return x;
}
int and_not(int a, int b)
{
	return a & ~ (b - 1);
}

int main()
{
	int num_a, num_b, res, div;

	num_a = input();
	num_b = input();

	res = and_not(num_a, num_b);
	div = res / num_b;

	printf("res(%d) / num_b(%d) = div(%d)\n", res, num_b, div);
	printf("div(%d) / num_b(%d) = res(%d)\n", div, num_b, div * num_b);


	return 0;

}
