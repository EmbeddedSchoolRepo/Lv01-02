#include <stdio.h>

char trans_char(char character)
{
	char new_char = character ^ 0x20;

	return new_char;
}

int main(void)
{
	char character = 0;
	char new_char = 0;

	printf("영어  글자를 한 개 입력하세요: ");
	scanf("%c", &character);

	new_char = trans_char(character);	
	printf("변환된 결과는 %c 입니다.\n", new_char);

	return 0;
}
