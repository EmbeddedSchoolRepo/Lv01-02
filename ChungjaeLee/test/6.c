#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, n;

	printf("n입력: ");
	scanf("%d", &n);
	
	int* arr = malloc(sizeof(int) * n);
	
	arr[0] = 1;
	arr[1] = 6;
	arr[2] = 2;
	
	for(i = 3; i < n; i++)
	{	
		if((i % 2) == 1)
		{
			arr[i] = arr[i-3] + arr[i-1];
		}

		else if((i % 2) == 0)
		{
			arr[i] = arr[i-1] - arr[i-3];
		}
	}

		printf("%d번째항은 %d입니다.\n", n, arr[n-1]);
	
	free(arr);

	return 0;
}
