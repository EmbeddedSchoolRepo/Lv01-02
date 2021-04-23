#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int print_mat(int (*R)[2])
{
	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%3d ", R[i][j]);
		}
		printf("\n");
	}
}

int print_mat_float(float (*R)[2])
{
	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%3.2f  ", R[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int matrixA[2][2] = { 0 };
	float det = 0;
	float matrixA_det[2][2] = { 0 };

	int i,j;

	srand(time(NULL));

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			matrixA[i][j] = rand() % 10 + 1;
		}
	}

	det = (matrixA[0][0] * matrixA[1][1]) - (matrixA[0][1] * matrixA[1][0]);

	if (det == 0)
	{
		printf("can't find det \n");
		return -1;
	}

	matrixA_det[0][0] = matrixA[1][1] / det;
	matrixA_det[0][1] = (matrixA[0][1] * -1) / det;
	matrixA_det[1][0] = (matrixA[1][0] * -1) / det;
	matrixA_det[1][1] = matrixA[0][0] / det;


	printf("matrixA : \n");
	print_mat(matrixA);

	printf("matrixA_det : \n");
	print_mat_float(matrixA_det);

	return 0;

}
