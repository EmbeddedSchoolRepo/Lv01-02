#include <stdio.h>

int transeCharactor(char c);

int main(void)
{
	char sec_char;

	printf("글자를 한 개 입력하세요 : ");
	scanf("%c", &sec_char);

	transeCharactor(sec_char);

	return 0;	
}

int transeCharactor(char c)
{
	if ((c < 91 && c > 64) || (c > 96 && c < 123))
	{
		printf("입력한 글자는 = %c\n", c);
		printf("아스키 코드로 표현하면 = %d\n", c);

	
		printf("원래 : %c, 변환 후 : %c \n", c, c ^ 0x20);

		return 1;
	}


	return 0;
}
