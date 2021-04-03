#include <stdio.h>

void printCalendar(int year, int month);

char g_month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
	unsigned int year = 0;
	unsigned int month = 0;

	printf("Insert Year, month : ");
	scanf("%d %d", &year, &month);

	//exception
	while(1) 
	{
		if (year >= 0 && month >= 1 && month <= 12)
		{
			break;
		}
	
		printf("Insert Year, month : ");
		scanf("%d %d", &year, &month);
	}		

	printCalendar(year, month);
	
	return 0;
}

int isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return 1;
			}
			return 0;
		}
		return 1;
	}

	return 0;
}

void printCalendar(int year, int month)
{
	int i;
	unsigned int dayCount = 0;
	char daySpace = 0;
	char day;
	char space = 0;

	if (isLeapYear(year))
	{
		g_month_day[1] = 29;
	}


	for (i = 1; i < year; i++)
	{
		if (isLeapYear(i))
		{
			dayCount += 366;
		}
		else 
		{
			dayCount += 365;
		}
	}	

	dayCount += 365;

	//dayCount = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	
	for (i = 0; i < month - 1; i++)
	{
		dayCount += g_month_day[i];
	}

	daySpace = dayCount % 7;

	


printf("일\t월\t화\t수\t목\t금\t토\n");
	printf("----------------------------------------------------\n");

	for (i = 0; i < daySpace; i++)
	{
		printf("\t");
		space++;
	}


	day = g_month_day[month - 1];

	for (i = 1; i <= day; i++)
	{
		printf("%2d\t", i);
		if (space == 6)
		{
			printf("\n");
			space = 0;
		}
		else 
		{
			space++;
		}
	}	
	printf("\n");
}
