#include <stdio.h>

// void main(void) <<< 굉장히 안좋은 습관(특히 리눅스)
// 이유는 레벨 2 리눅스 시스템 프로그래밍 할 때 설명합니다.
// 프로세스(task)를 제어할 때 return 값이 결국 프로세스가 정상 종료했는지 비정상 종료했는지 상태값을 의미합니다.
// 그러나 void main(void)인 경우 이 프로세스가 정상 종료되었는지 비정상 종료되었는지 알 수가 없습니다.
// 그래서 void main(void)를 권장하지 않습니다.
int main(void)
{
	int num1 = 1;
	short num2 = 2;
	char num3 = 3;

	float num4 = 2.3f;
	double num5 = 2.8;

	long long int num6 = 10000000000;
	long double num7 = 2942723.2234;

	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
	printf("num3 = %d\n", num3);

	// yy: yank -> p: paste
	// u: 뒤로가기
	// ctrl + r: 앞으로가기
	printf("num4 = %f\n", num4);
	printf("num4 = %.2f\n", num4);
	printf("num5 = %lf\n", num5);

	// Ctrl + F: Page Down
	// Ctrl + B: Page Up
	printf("num6 = %lld\n", num6);
	printf("num7 = %Lf\n", num7);

	return 0;
}

// y숫자y -> 숫자만큼 라인을 복사합니다.
// dd -> 삭제하기
// d숫자d -> 숫자만큼 라인을 삭제합니다.
// :$ -> 무조건 마지막 라인으로 이동합니다.
// :set nu -> 현재 편집기의 라인을 숫자로 보여줍니다.
// :set nonu -> 편집기에 보이던 숫자를 끕니다.
