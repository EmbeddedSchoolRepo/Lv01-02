#include <stdio.h>

int main(void)
{
	int i, num;

	printf("1 ~ n까지 출력합니다. (n을 선택하세요): ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		if (!(i % 3))
		{
			continue;
		}

		printf("i = %3d\n", i);
	}

	return 0;
}
