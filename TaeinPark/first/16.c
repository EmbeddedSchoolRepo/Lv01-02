#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char res, al;
//	char A,B,C;
	char arr[] = {0};

	printf("알파벳 문자 하나를 입력하여 주세요. : ");
	scanf("%c", &al);

//	printf("%x", al);
	
//	al = arr[0];

	res = al^0x20;
//	res2 = arr[1]^0x20;
//	res3 = arr[2]^0x20;

	printf("%c\n",res);

	return 0;
}
