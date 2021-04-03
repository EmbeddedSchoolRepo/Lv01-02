#include<stdio.h>

char upperlower(char asc, char up, char low)
{
	if(asc >= 'a' && asc <= 'z')
	{
		return asc - low + up;
	}
	if (asc >= 'A' && asc <= 'Z')
	{
		return asc - up + low;
	}

}


int main(void) {

	char text, upper = 'A', lower = 'a';
	int res;
	printf("입력 문자(소문자/대문자)\n");
	scanf("%c", &text);

	res = upperlower(text, upper, lower);

	printf("결과 %c", res );



	return 0;
}
