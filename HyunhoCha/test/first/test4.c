#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	char age;
	char phone_number[20];
	char address[100];
} user;

bool insert_user(user *users)
{
	if(users == NULL)
	{
		return false;
	}

	scanf("%s %d %s %s", users->name, &users->age, users->phone_number, users->address);

	return true;
}

void print_age_group(user *users, int number)
{
	int i,j;

	for (i = 0; i < 3; i++)
	{
		printf("%d대 그룹 : \n", (i + 1) * 10);

		for (j = 0; j < number; j++)
		{
			if(users[j].age >= ((i + 1) * 10) && users[j].age < ((i + 2) * 10))
			{
				printf("이름 : %s\n", users[j].name);
				printf("나이 : %d\n", users[j].age);
			}

			printf("\n\n");
		}
	}

}

int main(void)
{
	user users[10];
	int user_number = 0;
	int user_table_size = 10;
	char ext = 0;


	while(ext != 'c')
	{
		if (user_number >= user_table_size)
		{
			break;
		}

		printf("사용자 정보 입력 (이름, 나이, 전화번호, 거주지) : ");
		
		if(insert_user(&users[user_number]) == false)
		{
			return -1;
		}		

		printf("종료하고 싶으면 c 입력 계속은 d: ");
		scanf("%s", &ext);

		user_number++;		
	}

	print_age_group(users, user_number);


	return 0;
}
