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

int main(void)
{
	int matA[2][2] = {
		{ 1, 0 },
		{ 0, 1 }
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

	printf("mat A + B:\n");
	matR = add_mat(matA, matB);
	print_mat(matR);

	free(matR);

	return 0;
}
