#include <stdio.h>

//피보나치와 유사한 패턴을 가짐.
//피보나치와 차이점은 n번째 항과 n+4번째항 더한 값이 다음항 이라는 것.

int sequence_num(int index)
{
	int res=0;
	int num1=1;
	int num2=1;
	int num3=1;
	int num4=1;
	int i;

	if(index <= 0)
	{
		return 0;
	}
	else if(index <= 4)
	{
		return 1;
	}
	else
	{
		for(i=5; i<=index; i++)
		{
			res = num1 + num2;
			num1 = num2;
			num2 = num3;
			num3 = num4;
			num4 = res;
		}
	}
	return res;
}

int main(void)
{
	int res, index;

	printf("수열의 몇 번째 항의 값을 원하는지 적어 주세요 : ");
	scanf("%d", &index);

	res=sequence_num(index);

	printf("%d 항의 값은 %d 입니다. \n", index, res);

	return 0;
}
