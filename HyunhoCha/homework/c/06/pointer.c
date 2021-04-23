#include <stdio.h>
#include <time.h>


int main(void)
{
	int *p_array1[10] = { 0 };
	int (*p_array2)[10];
	int array[10] = { 0 };

	p_array2 = array;

	printf("p_array1 = %x \n", p_array1);
	printf("p_array1 + 1 = %x \n", p_array1 + 1);

	printf("p_array2 = %x \n", p_array2);
	printf("p_array2 + 1 = %x \n", p_array2 + 1);


	return 0;
}
