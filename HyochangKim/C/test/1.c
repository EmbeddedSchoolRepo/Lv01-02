#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct member
{
	char name[10];
	int age[10];
	int contact[11];
	char residence[40];
	
};

void join(struct member *info)
{
	int i;
	for(i = 0; i < 100; i++)
	{
		printf("이름 입력 : ");
		scanf("%s", info[i].name);
		printf("\n");
		printf("나이 입력 : ");
		scanf("s", info[i].age);
		printf("\n");
		printf("전화번호 입력 : ");
		scanf("s", info[i].contact);
		printf("\n");
		printf("거주지를 입력 : ");
		scanf("s", info[i].residence);
		
	}

void list(struct member *info)
{ 
	int i, j, 
	char same = info[i].residence;
	
	printf("저장되어 있는 정보 중에 거주지 하나 선택\n");
	scanf("s",&same);
	
	printf(" 동일한 거주지인 회원을 몇 명이나 출력할 것인가\n);
	scanf("d", &j);
	
	for(i = 0; i < 100; i++)
	{
		if(info[i].residence != same)
		{
			continue;		
		}	
		else if(info[i] == same)
		{	
			for(i = 0; i < j; i++)
			{	
				printf("이름 : %s, 나이 : %s, 전화번호 : %s, 거주지 : %s\n", info[i].name, info[i].age, info[i].contact, info[i].residence);
				break;
			}
		}
	}
}

int main()
{
	while(i !=0)
	{
		struct member info[100];
		int i;
		printf("회원 이름\n");
		printf("회원 나이\n");
		printf("회원 전화번호\n"):
		printf("회원 거주지\n");
		scanf("%d", &i);
		printf("\n");
	
		if(i == 1)
		{
			join(info);
			i = 0;
		}
	
		if(i == 2)
		{
			list(info);
		}
	
		if(i == 3)
		break;
	}
		
	return 0;
}


