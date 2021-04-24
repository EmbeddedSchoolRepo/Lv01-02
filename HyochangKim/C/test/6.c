#include <stdio.h>

int main(void)
{
	int i;
	int num;
	int arr[20] = {0};
	
	int len = sizeof(arr) / sizeof(int);
	printf("20번째 숫자를 구하세요\n");
	
	arr[0] = 1;
	arr[1] = 6;
	
	for(i = 0; i < 20; i++)
	{
		arr[i] = arr[i -1] + arr[i - 2];
	}
	
	printf("20번째는 %d\n", arr[num-1]);
	
	return 0;
}
