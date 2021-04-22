#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	int i, j, k, random;

	printf("딥러닝 연산중임\n");
	printf("Tensor 기반 연산이다보니 시간이 for 루프가 많음\n");
	printf("하드웨어 장치에서 데이터를 가져와서 처리하고 있음\n");
	printf("그런데 데이터가 갑자기 누락되어서 연산 자체를 폐기해야 하는 상황임\n");
	printf("우리가 실제 에러를 만들 순 없으니 특정한 순간을 가정하고 진행함\n");

	// 난수 생성을 위한 시드값 초기화
	srand(time(NULL));
	random = rand() % 3;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if (j == random)
				{
					printf("data: %3d, Error!\n", random);
				}

				printf("i = %3d, j = %3d, k = %d\n", i, j, k);
			}
		}
	}

	return 0;
}
