#include <stdio.h>

int main(void)
{
	int num;

	// 여기서 보이는 &는 주소값을 주세요 ~
	// 라는 의미를 가지고 있는 녀석으로
	// 오늘 오지게 ? 설명했던 메모리 주소를 달라는 뜻입니다.

	// 즉 num 변수의 주소에 제가 키보드로 입력한 값을 넣어주세요가 scanf 입니다.
	printf("원하는 정수값을 입력해보세요: ");
	scanf("%d", &num);

	printf("입력한 정수값은 = %d\n", num);

	return 0;
}
