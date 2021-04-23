#include <stdio.h>
#include <stdlib.h>

void init_vector(int *vector, int len)
{
	int i;

	for(i=0; i<len;i++)
	{
		vector[i]=rand() %8 +1;
	}
}

void printf_vector(int *vector, int len)
{
	int i;

	for(i=0; i<len; i++)
	{
		printf("%3d", vector[i]);
	}
	printf("\n");
}

int *add_vector(int *vec_A, int *vec_B, int len_A, int len_B)
{
	int i;

	if(len_A != len_B)
	{
		printf("이 연산을 수행 할 수 없습니다. \n");

		return NULL;
	}

	int *tmp = (int *)malloc(sizeof(int) * len_A);

	for(i=0; i<len_A; i++)
	{
		tmp[i] = vec_A[i] + vec_B[i];
	}
	return tmp;
}

float dot_product(int *vec_A, int *vec_B, int len_A, int len_B)
{
	int i;
	float sum = 0;

	if(len_A != len_B)
	{
		printf("두 벡터의 연산은 불가능 하다. \n");

		return -1;
	}

	for(i=0; i<len_A; i++)
	{
		sum += vec_A[i] * vec_B[i];
	}

	return sum;
}

int main(void)
{
	int len_A, len_B, len_U, len_V;
	int vectorA[3] = { 0 };
	int vectorB[3] = { 0 };
	int vecU[3] = {1, -2, -1};
	int vecV[3] = {-2, 0, -2};
	int *vectorR;

	len_A = sizeof(vectorA) / sizeof(int);
	len_B = sizeof(vectorB) / sizeof(int);
	len_U = sizeof(vecU) / sizeof(int);
	len_V = sizeof(vecV) / sizeof(int);

	srand(time(NULL));

	init_vector(vectorA, len_A);
	init_vector(vectorB, len_B);

	printf("vector A : \n");
	printf_vector(vectorA, len_A);
	printf("vector B : \n");
	printf_vector(vectorB, len_B);

	printf("vector A + B:\n");
	vectorR = add_vector(vectorA, vectorB, len_A, len_B);
	printf_vector(vectorR, len_A);

	printf("Inner Product:\n");
	printf("두 개의 벡터가 서로 수직한가 ?\n");
	printf("res = %f\n", dot_product(vecU, vecV, len_U, len_V));
	printf("res = %f\n", dot_product(vectorA, vectorB, len_A, len_B));
	

	return 0;
}






