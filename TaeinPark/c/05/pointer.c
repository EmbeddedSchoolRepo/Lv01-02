#include <stdio.h>

int main(void)
{
	int num=7;
	int *pointer = &num;

	printf("num = 0x%x\n", num);
	printf("pointer = 0x%x\n", pointer);
	printf("*poiter = 0x%x\n", *pointer);

	return 0;
}
