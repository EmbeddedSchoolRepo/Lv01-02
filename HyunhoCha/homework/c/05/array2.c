#include <stdio.h>

int main(void)
{
	int array[10] = {0};
	int i;

	printf ("array[0]의 주소 : 0x%8x\n", &array[0]);
	printf ("array[0]의 값 : 0\n", array[0]);
	printf ("array : 0x%8x\n", array);

	return 0;
}
