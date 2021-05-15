#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, len;
	char arr[30];

	printf("문자열을 입력하세요.: ");
	scanf("%s", arr);

	len = strlen(arr);
	for(i = 0; i < len; i++)
	{
		arr[i] ^= 0x20; 
	}

	printf("%s\n", arr);
	
	return 0;
}
