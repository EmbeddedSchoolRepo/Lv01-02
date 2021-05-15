#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person person;

struct person
{
	char* name;
	int age;
	char* PhoneNumber;
	char* province;
};



void get_information(person* p, int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		p[i].name = (char*)malloc(sizeof(person));
		p[i].PhoneNumber = (char*)malloc(sizeof(person));
		p[i].province = (char*)malloc(sizeof(person));

		printf("이름을 입력하세요: ");
		scanf("%s", p[i].name); 
	
		printf("나이를 입력하세요.: ");
		scanf("%d",&p[i].age);
	
		printf("전화번호를 입력하세요: ");
		scanf("%s", p[i].PhoneNumber);

		printf("거주지역을 입력하세요(도단위): ");
		scanf("%s", p[i].province);

		printf("\n");
	}
}

void print_info(person* p, int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		printf("%s\n",p[i].name);
		printf("%d\n", p[i].age);
		printf("%s\n", p[i].PhoneNumber);
		printf("%s\n", p[i].province);
		printf("\n");
	}
}
		
void print_condition_age(person* p, int len)
{
	int i, num;

	printf("알고싶은 나이대를 입력하세요: ");	
	scanf("%d", &num);

	for(i = 0; i < len; i++)
	{
		if(p[i].age / num == 1)
		{
			printf("%s  ", p[i].name);
		}
	}
	printf("\n\n");
}




void print_condition_city(person* p, int len)
{	
	int i;
	
	printf("집이 경기도인 사람은? ");

	for(i = 0; i < len; i++)
	{
		if(strcmp(p[i].province, "경기") == 0)
		{
			printf("%s ",p[i].name);
		}
	}
		printf("\n");
	

	printf("집이 충청도인 사람은? ");
	
	for(i = 0; i < len; i++)
	{
		if(strcmp(p[i].province, "충청") == 0)
		{
			printf("%s ", p[i].name);
		}
	}	
		printf("\n");
	
	printf("집이 강원도인 사람은? ");
	
	for(i = 0; i < len; i++)
	{
		if(strcmp(p[i].province, "강원") == 0)
		{
			printf("%s ", p[i].name);
		}
	}	
		printf("\n");

	printf("집이 전라도인 사람은? ");
	
	for(i = 0; i < len; i++)
	{
		if(strcmp(p[i].province, "전라") == 0)
		{
			printf("%s ", p[i].name);
		}
	}
		printf("\n");

	printf("집이 경상도인 사람은? ");
	
	for(i = 0; i < len; i++)
	{
		if(strcmp(p[i].province, "경상") == 0)
		{
			printf("%s ", p[i].name);
		}
	}	
		printf("\n");
	
	printf("집이 제주도인 사람은? ");
	
	for(i = 0; i < len; i++)
	{
		if(strcmp(p[i].province, "제주") == 0)
		{
			printf("%s ", p[i].name);
		}
	}	
		printf("\n\n");
}

void free_p(person* p, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		free(p[i].name);
		free(p[i].PhoneNumber);
		free(p[i].province);
	}
}

int main(void)
{
	
	person p[3];

	int len = sizeof(p) / sizeof(person);

	get_information(p, len);
	
	print_condition_age(p, len);

	print_condition_city(p, len);

	free_p(p, len);

	return 0;
}
