#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_MX_n(int n)
{
	int res = rand() % n + 1;
	return res;
}

void notdup_random_MX_n(int* random, int* check, int n)
{
	int i, res;
 
	for(i = 0; i < n; i++)
	{	
        	res = random_MX_n(n);

		while(check[res - 1] == 1)
		{	
				res = random_MX_n(n);
		}
		
			random[i] = res;
			check[res - 1] = 1;	
	}	
	
	
		for(i = 0; i < n; i++)
		{
			printf("%d\n", random[i]);
		}
	
}


int main(void)
{
	srand(time(NULL));

	int num;
	printf("반복횟수를 입력하세요.: ");
	scanf("%d", &num);
	
	int* random = malloc(sizeof(int) * num);
	int* check = malloc(sizeof(int) * num);

	notdup_random_MX_n(random, check, num);
	
	free(random);
	free(check);

	return 0;
}
