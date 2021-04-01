#include <stdio.h>

int main(void)
{
	char sec_char;
	printf("암호 글자를 한 개 입력 하세요: ");
	scanf("%c", &sec_char);

	printf("입력한 글자는 =  %c\n", sec_char);
	printf("또한 ASCII로 표현하면 = %d\n", sec_char);

	printf("대문자는 소문자가 되고 소문자는 대문자가 된다.\n");
	printf("원래는 %c, 지금은 %c\n", sec_char, sec_char^0x20);

	return 0;
}
