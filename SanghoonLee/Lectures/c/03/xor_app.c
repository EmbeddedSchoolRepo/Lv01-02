#include <stdio.h>

int main(void)
{
	char sec_char;
	printf("암호 글자를 한 개 입력하세요: ");
	scanf("%c", &sec_char);

	printf("입력한 글자는 = %c\n", sec_char);
	printf("또한 ASCII로 표현하면 = %d\n", sec_char);

	// 대문자 소문자 변환하기
	// 먼저 대문자인지 파악하고 + 32
	// 소문자면 - 32

	// 0x20은 16진수 표기이며 10진수로 32에 해당합니다.
	// 16 x 2 = 32
	printf("대문자는 소문자가 되고 소문자는 대문자가 된다.\n");
	printf("원래는 %c, 지금은 %c\n", sec_char, sec_char ^ 0x20);

	return 0;
}
