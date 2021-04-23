#include <stdio.h>
#include <stdlib.h>

int print_mat(int (*R)[2])
{
	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%3d", R[i][j]);
		}
		printf("\n");
	}
}

int (* add_mat(int (*A)[2], int (*B)[2]))[2]
{
	int i, j;

	int (*tmp)[2] = (int (*)[2])malloc(sizeof(int) * 4);

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			tmp[i][j] = A[i][j] + B[i][j];
		}
	}

	return tmp;
}

int dot_product(int *vec_A, int *vec_B, int len_A, int len_B)
{
	int i;
	int sum = 0;

	if (len_A != len_B)
	{
		printf("두 벡터의 연산은 불가능 하다\n");
		return -1;
	}

	for (i = 0; i < len_A; i++)
	{
		sum += vec_A[i] * vec_B[i];
	}

	return sum;
}

int (* matrix_mul(int (*matrixA)[2], int (*matrixB)[2]))[2]
{
	int i,j;
	int (*tmp)[2] = (int (*)[2])malloc(sizeof(int) * 4);	
	int vectorA[2] = { 0 };
	int vectorB[2] = { 0 };

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			vectorA[0] = matrixA[i][0];
			vectorA[1] = matrixA[i][1];
			vectorB[0] = matrixB[0][j];
			vectorB[1] = matrixB[1][j];

			tmp[i][j] = dot_product(vectorA, vectorB, 2, 2); 
		}
	}

	return tmp;
}

int main(void)
{
	int matA[2][2] = {
		{ 1, 1 },
		{ 1, 1 }
	};
	int matB[2][2] = {
		{ 3, 3 },
		{ 3, 3 }
	};

	int (*matR)[2];

	printf("mat A:\n");
	print_mat(matA);

	printf("mat B:\n");
	print_mat(matB);

	printf("mat AB:\n");
	matR = matrix_mul(matA, matB);
	print_mat(matR);

	free(matR);

	return 0;
}
