#include <stdio.h>

int main(void)
{
	int i, n;
	int arr[30] = {0, };
	
	arr[0] = 1;
	arr[1] = 6;
	arr[2] = 2;
	arr[3] = 3;

	printf("n입력: \n");
	scanf("%d", &n);

	for(i = 4; i < n; i++)
	{
		if((i%2) == 1)
		{
			arr[i] = arr[i-3] + arr[i-1];
		}

		else if((i%2) == 0)
		{
			arr[i] = arr[i-1] - arr[i-3];
		}
	}

	printf("%d번째항은 %d입니다.\n", n, arr[n-1]);

	return 0;
}
