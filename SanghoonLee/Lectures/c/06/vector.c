#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// 배열의 이름은 대표 주소 <<<
// 그러니까 포인터가
// 배열의 대표 주소를 인자로 받을 수 있다.
void init_vector(int *vector, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		vector[i] = rand() % 8 + 1;
	}
}

void print_vector(int *vector, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		printf("%3d", vector[i]);
	}

	printf("\n");
}

int *add_vector(int *vec_A, int *vec_B, int len_A, int len_B)
{
	int i;

	if (len_A != len_B)
	{
		printf("이 연산을 수행할 수 없습니다!\n");
		return NULL;
	}

	// malloc()
	// Stack | Heap | Data | Text
	// 이 중에서 malloc(), calloc()등의
	// 동적 할당을 수행하는 녀석들은
	// 모두 Heap 메모리에 할당된다.
	// 동적 할당이라 자유롭지만
	// 그만큼 성능은 떨어지게 된다.

	// 또한 기본 리턴 타입이 void * 이므로
	// 아래와 같이 사용하려는 데이터 타입에 맞게
	// 형 변환을 해줘야 하며
	// 사용하려는 바이트 수를
	// 입력 인자로 설정해줘야 한다.
	int *tmp = (int *)malloc(sizeof(int) * len_A);

	for (i = 0; i < len_A; i++)
	{
		tmp[i] = vec_A[i] + vec_B[i];
	}

	return tmp;
}

// cos(90) = 0
// 내적의 특성을 통해 두 벡터가 서로 수직한지 확인한다.
// 각 원소간의 곱의 덧셈으로도 내적이 가능하며
// 여기서 0이 나온다는 뜻은 두 벡터가 수직함을 의미한다.
float dot_product(int *vec_A, int *vec_B, int len_A, int len_B)
{
	int i;
	float sum = 0;

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

int main(void)
{
	int len_A, len_B, len_U, len_V;
	int vectorA[3] = { 0 };
	int vectorB[3] = { 0 };
	int vecU[3] = { 1, -2, -1 };
	int vecV[3] = { -2, 0, -2 };
	int *vectorR;

	len_A = sizeof(vectorA) / sizeof(int);
	len_B = sizeof(vectorB) / sizeof(int);
	len_U = sizeof(vecU) / sizeof(int);
	len_V = sizeof(vecV) / sizeof(int);

	srand(time(NULL));

	// 배열의 이름은 배열의 대표 주소
	// 배열을 실제 메모리상에 순차적으로 배치됨
	// 배열의 대표주소에서 일정한 거리를
	// 지속적으로 이동한다면
	// 원소를 모두 순회할 수 있을 것이다.
	init_vector(vectorA, len_A);
	init_vector(vectorB, len_B);

	printf("vector A:\n");
	print_vector(vectorA, len_A);
	printf("vector B:\n");
	print_vector(vectorB, len_B);

	printf("vector A + B:\n");
	vectorR = add_vector(vectorA, vectorB, len_A, len_B);
	print_vector(vectorR, len_A);

	printf("Inner Product:\n");
	printf("두 개의 벡터가 서로 수직한가 ?\n");
	printf("res = %f\n", dot_product(vecU, vecV, len_U, len_V));
	printf("res = %f\n", dot_product(vectorA, vectorB, len_A, len_B));

	return 0;
}
