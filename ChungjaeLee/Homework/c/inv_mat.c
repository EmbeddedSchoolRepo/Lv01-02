#include <stdio.h>
#include <stdlib.h>

int det2(float (*A)[2])
{
	int det = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	return det;
}

float(*revmat(float (*arr)[2]))[2]
{
	int i, j, a;
	float (*rev_arr)[2] = (float(*)[2])malloc(sizeof(float) * 4);

	a = det2(arr);

	rev_arr[0][0] = arr[1][1] / a;
	rev_arr[0][1] = -arr[0][1] / a;
	rev_arr[1][0] = -arr[1][0] / a;
	rev_arr[1][1] = arr[0][0] / a;
	
	return rev_arr;
}

void print_mat(float (*arr)[2])
{
	int i, j;
	
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%.2f  ", arr[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int det;
	float matA[2][2] =
	{
		{3, 1},
		{2, 1}
	};

	float (*rev_A)[2];

        det = det2(matA); 
	
	if(det == 0)
	{
		printf("error\n");
	}
	else 
	{
		rev_A = revmat(matA);
	
		printf("matA:\n");
		print_mat(matA);

		printf("matB:\n");
		print_mat(rev_A);
	}

	return 0;
}
