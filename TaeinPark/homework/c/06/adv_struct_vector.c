#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define VEC_DIMENSION			3

typedef struct vector vec;

struct vector
{
	int vector[3];
	int len;
};

void init_vector(vec *v)
{
	int i;

	for (i = 0; i < VEC_DIMENSION; i++)
	{
		// 어떤 수를 7로 나눈 나머지는 ? 0 ~ 6
		// 위 범위 전체에 + 1을 하면 ? 1 ~ 7
		v->vector[i] = rand() % 7 + 1;
	}

	v->len = VEC_DIMENSION;
}

void print_vector(vec v)
{
	int i;

	for (i = 0; i < v.len; i++)
	{
		printf("%3d", v.vector[i]);
	}

	printf("\n");
}

vec *add_vector(vec v, vec u)
{
	int i;

	if (v.len != u.len)
	{
		printf("이 연산을 수행할 수 없습니다!\n");
		return NULL;
	}

	vec *tmp = (vec *)malloc(sizeof(vec));

	for (i = 0; i < v.len; i++)
	{
		tmp->vector[i] = v.vector[i] + u.vector[i];
	}

	tmp->len = v.len;

	return tmp;
}

int main(void)
{
	vec vecU;
	vec vecV;
	vec *vecR;

	srand(time(NULL));

	init_vector(&vecU);
	init_vector(&vecV);

	printf("vector U:\n");
	print_vector(vecU);
	printf("vector V:\n");
	print_vector(vecV);

	printf("vector U + V:\n");
	vecR = add_vector(vecV, vecU);
	print_vector(*vecR);

	free(vecR);

	return 0;
}
