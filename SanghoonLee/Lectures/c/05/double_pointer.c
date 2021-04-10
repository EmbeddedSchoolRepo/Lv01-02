#include <stdio.h>

int main(void)
{
	int num = 3;
	int *p_num = &num;
	int **pp_num = &p_num;

	// p7_num;

	printf("num = %d\n", num);
	printf("*p_num = %d\n", *p_num);
	printf("**pp_num = %d\n", **pp_num);

	printf("&num = 0x%x\n", &num);
	printf("p_num = 0x%x\n", p_num);

	printf("&p_num = 0x%x\n", &p_num);
	printf("pp_num = 0x%x\n", pp_num);

	printf("&pp_num = 0x%x\n", &pp_num);

	return 0;
}
