#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define VECTOR_SIZE 3


float *crossproduct(float *vectorA, float *vectorB, int len_A, int len_B)
{
	int i;
	float *tmp = (float*)malloc(sizeof(float*) * VECTOR_SIZE);	

	
	tmp[0] = vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1];
	tmp[1] = vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2];
	tmp[2] = vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0];

 	return tmp;
}

void print_vector(float *vector, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		printf("%02.2f  ",vector[i]);
	}

	printf("\n");
}

int main(void)
{
	int i;
	float vectorA[VECTOR_SIZE] = { 0.0 };
	float vectorB[VECTOR_SIZE] = { 0.0 };
	float* result;

	srand(time(NULL));
  
  	for (i = 0; i < VECTOR_SIZE; i++)
    {
    	vectorA[i] = rand() % 10 + 1;
    	vectorB[i] = rand() % 10 + 1;
    }

	printf("vectorA :");
    print_vector(vectorA, VECTOR_SIZE);
		
	printf("veoctrB :");
    print_vector(vectorB, VECTOR_SIZE);

	result = crossproduct(vectorA, vectorB, 3, 3);
	printf("A B crossproduct :");
	print_vector(result, VECTOR_SIZE);

	free(result);
	return 0;
}
