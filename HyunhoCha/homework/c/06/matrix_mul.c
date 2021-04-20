#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 3

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

int** matrix_mul(int **matrixA, int **matrixB)
{


}

int main(void)
{
	int matrixA[MATRIX_SIZE][MATRIX_SIZE] = { 0 };
	int matrixB[MATRIX_SIZE][MATRIX_SIZE] = { 0 };
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

	return 0;
}
