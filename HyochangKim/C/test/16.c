#include<stdio.h>
{
	char str[100];
	int i;
	printf("대문자된 문자열 입력:"\n);
	scanf("%s", str);
	
	for(i = 0; str[i]; i++)
	{
		str[i] = char(tolower(str[i]);
	}
	
	printf	("소문자 출력 : %s\n", str);
	return 0;
}
