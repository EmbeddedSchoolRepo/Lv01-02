#include <stdio.h>

// 첫항, 둘째항이 각각 1, 셋째항 부터는 앞 두개의 항을 더한 값이다.
// n번째 항이 인덱스로 들어오면 for 문에서 3번째 항부터 반복분을 실행.
// 이때 결과는 앞의 두개의 숫자를 더한 값이 되고
// 앞의 두개의 숫자는 매번 반복문이 실행 될 때 마다 업데이트.

int fibo_num(int index)
{
	int res=0;
	int num1=1;
	int num2=1;
	int i;

	if(index <= 0)
	{
		return 0;
	}
	else if(index <= 2)
	{
		return 1;
	}
	else
	{
		for(i=3; i<=index; i++)
		{
			res = num1 + num2;
			num1 = num2;
			num2 = res;
		}
	}
	return res;
}

int main(void)
{
	int res, index;

	printf("피보나치 수열의 몇 번째 항의 값을 원하는지 적어 주세요 : ");
	scanf("%d", &index);

	res=fibo_num(index);

	printf("%d 항의 값은 %d 입니다. \n", index, res);

	return 0;
}
