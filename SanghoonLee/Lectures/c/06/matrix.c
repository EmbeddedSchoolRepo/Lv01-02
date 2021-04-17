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

// 뭐 이런 문법이 다 있을까 ?
// C언어의 창시자인 켄 톰슨과 데니스 리치의 저서에 설명되어 있듯이
// C언어는 문법 자체에 포인터라는 특성 때문에
// 특수문자를 연달아 배치할 수 없다.
// 이로 인해 int[2] *를 int (*)[2] 형태로 표현해야 한다.
// 그러므로 원래라면
// int[2] *add_mat(int[2] *A, int[2] *B)를 아래와 같이 표기한다.
// int (*)[2] add_mat(int (*A)[2], int (*B)[2])

// 배열을 리턴할 수 있는 고오급 기법
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

	// 이게 뭐지 ?
	// int *matR[2] -> int *    matR[2]
	// 위 코드와 아래 코드는 완전히 다른 것
	// int (*)[2]     matR;
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
