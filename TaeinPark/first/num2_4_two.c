#include <stdio.h>












int main(void)
{
	char name[10];
	char address[20];
	int age;
	int phone;
	
	printf("이름을 입력 하세요. : ");
	scanf("%s", name);
	
	printf("거주지를 입력 하세요. : ");
	scanf("%s", address);

	printf("나이를 입력 하세요. : ");
	scanf("%d", &age);

	printf("전화번호를 입력 하세요. ");
	scanf("%d", &phone);

	printf("당신의 이름은 %s \n 거주지는 %s \n 나이는 %d \n 전화번호는 0%d 입니다.\n",name, address, age, phone);
	
		



	return 0;
}
