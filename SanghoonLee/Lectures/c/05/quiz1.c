#include <stdio.h>

int main(void)
{
	int i;
	int num;
	int arr[30] = { 0 };
	// sizeof()는 전체 바이트 수를 구해옴
	// arr의 바이트 수는 30 * 4로 120이며
	// int형의 데이터타입은 4이므로
	// len은 30이라는 결론을 도출함
	int len = sizeof(arr) / sizeof(int);

	printf("구하고 싶은 n 번째 피보나치 항을 입력하세요: ");
	scanf("%d", &num);

	arr[0] = 1;
	arr[1] = 1;

	for (i = 2; i < num; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("n 번째 피보나치 항은 %d\n", arr[num - 1]);

	return 0;
}
