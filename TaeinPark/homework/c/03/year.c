
// 4로 나누어 떨어지고(&&) 100으로 나누어 떨어지지 않으면 윤년
// 400으로 나누어 떨어지면 윤년

#include <stdio.h>

int my_year(int year)
{
	if(((year%4==0) && (year%100!=0)) || (year%400==0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int year,res;

	printf("년도를 입력해 주세요. : ");
	scanf("%d", &year);

	res = my_year(year);

	if(res==1)
	{
		printf("%d 년은 윤년 입니다. \n", year);
	}
	if(res==0)
	{
		printf("%d 년은 윤년이 아닙니다. \n", year);
	}

	return 0;
}

