#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MATRIX_SIZE 2

void print_mat(int (*R)[2])
{
	int i, j;

	for (i = 0; i < MATRIX_SIZE; i++)
	{
		for (j = 0; j < MATRIX_SIZE; j++)
		{
			printf("%3d", R[i][j]);
		}
		printf("\n");
	}
}

int dot_product(int *vectorA, int *vectorB)
{
	int result = 0;
	int i;

	for (i = 0; i < 2; i++)
	{
		result += vectorA[i] * vectorB[i];
	}

	return result;
}

void matrix_transposition(int **matrix)
{
	int i,j;
	int temp;
	
	temp = matrix[0][1];
	matrix[0][1] = matrix[1][0];
	matrix[1][0] = temp;
}

int (* matrix_mul(int (*matrixA)[2], int (*matrixB)[2], int len_A, int len_B))[2]
{
	int i,j;
	int (*tmp)[2];
	int vectorB[2] = { 0 };
	int vectorA[2] = { 0 };

	if (len_A != len_B)
	{
		printf("can't matrix multiple \n");
		return NULL;
	}

	tmp = (int(*)[2])malloc(sizeof(int) * 4);

	matrix_transposition(matrixB);

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			tmp[i][j] = dot_product(matrixA[i], matrixB[i]);
		}
	}

	return tmp;
}


int main(void)
{
	int matrixA[MATRIX_SIZE][MATRIX_SIZE] = { 0 };
	int matrixB[MATRIX_SIZE][MATRIX_SIZE] = { 0 };
 	int (*result)[2];
	int i, j;

	srand(time(NULL));

	for (i = 0; i < MATRIX_SIZE; i++)
	{
		for (j = 0; j < MATRIX_SIZE; j++)
		{
			matrixA[i][j] = rand() % 10 + 1;
			matrixB[i][j] = rand() % 10 + 1;
		}
	}

	printf("matrixA :\n");
	print_mat(matrixA);


	printf("matrixB :\n");
	print_mat(matrixB);

	result = matrix_mul(matrixA, matrixB, 2, 2);
	printf("matrixA x matrixB :\n");
	print_mat(result);
		
	free(result);

	return 0;
}
