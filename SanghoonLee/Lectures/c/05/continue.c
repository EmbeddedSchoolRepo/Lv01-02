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
			// 다시 위로 돌아감(증감부를 수행하게됨)
			// 결국 아래의 printf를 실행하지 않고 스킵하게 됨
			continue;
		}

		printf("i = %3d\n", i);
	}

	return 0;
}
