#include <stdio.h>

int main(void)
{
	int i, len;
	char arr[] = "APPLE";
	len = sizeof(arr) / sizeof(char);

	for(i = 0; i < len; i++)
	{
		arr[i] ^= 0x20; 
	}

	printf("%s\n", arr);

	return 0;
}
