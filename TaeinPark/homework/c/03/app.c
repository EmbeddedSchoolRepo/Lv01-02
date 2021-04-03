#include <stdio.h>

char ex_change(char one)
{
	char res;

	res = one^0x20;

	return res;
}

int main(void)
{
	char sec_char, res;

	printf("알파벳 문자 하나를 입력 하여 주세요. : ");
	scanf("%c", &sec_char);

	res = ex_change(sec_char);

	printf("입력한 문자는 %c, 지금은 %c 입니다. \n", sec_char, res);

	return 0;
}

