#include <stdio.h>

int main() 
{
	int num1 = 100;
	int num2 = 200;
	int num3 = 300;

	int*arr[3] = {&num1, &num2, &num3};

	for(int i=0; i<3; i++)
	{
		printf("arr[%d] = 주소값 : %p / 값 :%d\n", i,arr[i], *arr[i]);
	}
}

