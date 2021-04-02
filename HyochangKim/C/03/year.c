#include<stdio.h>

int year2020(int year)
{
    if(((year % 4) ==0) && ((year % 100) != 0) || ((year % 400) == 0))
        return 1;    
    else return 0;
}
//윤달이면 1을 리턴하고 아니면 0을 리턴하는 함수


int main(void) 
{
	int yyyy, res;
	printf("년도 입력\n");
	scanf("%d", &yyyy); 
	
	res =  year2020(yyyy);
	
	if(res == 1)
	{
		 printf("2월  29일  윤년입니다",res);
	}
	else if(res == 0)
	{
		 printf("2월  28일  윤년이 아닙니다 ",res);
	}
	
	return 0;
}
