#include <stdio.h>



struct info
{
	char *name;
	int age;
	int phone;
	char *home;
}

void pirnt_struct(struct info sample)
{
	printf("name = %s\n", sample.name);

}
int main(void)
{
	struct info sample;

	print_struct(sample); 	

	return 0;
}

	
	
