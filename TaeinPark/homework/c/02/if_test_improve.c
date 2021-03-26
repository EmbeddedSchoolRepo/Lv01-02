#include <stdio.h>

int main(void)
{
	int num1, num2;

	// 아래와 같은 형식으로 정수 두 개를 입력 받을 수 있습니다.
	printf("두 개의 정ㅅ를 입력하세요 : ");
	scanf("%d %d", &num1, &num2);

	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);

	// 범주를 여기서 크게 잡아 버리면
	// 아래쪽에서 범주가 작은 녀석들을
	// 큰 녀석이 포함관계로 전부 덮어버릴 수가 있으니 주의
	
	// 입력 값이 0 ~ 99
	// if (100 > num)
	// else if(50 > num)
	// else if(20 > num)
	
	// 입력 값이 0 ~ 99
	// if (20 > num)
	// else if(50 > num)
	// else if(100 > num)
	if (num1 > num2)
	{
		printf("num1(%d)가 num2(%d) 보다 큽니다.\n", num1, num2);
	}
	else if(num1 < num2)
	{
		printf("num2(%d)가 num1(%d) 보다 큽니다.\n", num2, num1);
	}
	else
	{
		printf("num1(%d)와 num2(%d)는 서로 같습니다.\n", num1, num2);
	}
	// 첫 번째 조건이 만족되지 않았을 경우
	// 또 다른 조건을 추가하고 싶다면 else if 형식을 사용하면 됩니다.
	
	return 0;
}
