#include <stdio.h>

//짝수 출력
int even_num(void)
{
	int i;
	int count;

	for(i=0; i<100; i++)
	{
		if(!(i%2))
		{
			printf("%d ",i);
			count++;
		}
		if(count > 10)
		{
			printf("\n");
			count=0;
		}
	}
	printf("\n");

	return 0;
}

//홀수 출력 함수
int odd_num(void)
{
	int i;
	int count;

	for(i=0; i<100; i++)
	{
		if(i%2)
		{
			printf("%d ",i);
			count++;
		}
		if(count > 10)
		{
			printf("\n");
			count=0;
		}
	}
	printf("\n");

	return 0;
}

int main(void)
{
	int index;

	printf("홀수를 출력 하려면 '1'을, 짝수를 출력 하려면 '2'를 입력 하여 주세요 : ");
        scanf("%d", &index);

	if(index==1)
	{
		odd_num();
	}
	else if(index==2)
	{
		even_num();
	}

	return 0;
}



