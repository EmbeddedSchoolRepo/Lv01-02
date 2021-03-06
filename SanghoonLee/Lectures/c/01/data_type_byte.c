#include <stdio.h>

int main(void)
{
	// %d를 %lu로 바꾸라는 워닝 메시지가 발생함
	// 7개를 바꿔야 하는데 일일히 바꾸기 귀찮음 어떻게 해야할까 ?
	// :%s/%d/%lu/g -> 모든 %d를 찾아서 %lu로 치환해주세요.
	//                 모든 -> /g
	//                 치환 -> :%s
	//                 치환 대상 -> %d
	//                 치환 결과 -> %lu
	// sizeof()는 데이터 타입의 크기를 바이트 단위로 표현해줍니다.
	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(short) = %lu\n", sizeof(short));
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(long long int) = %lu\n", sizeof(long long int));

	printf("sizeof(float) = %lu\n", sizeof(float));
	printf("sizeof(double) = %lu\n", sizeof(double));
	printf("sizeof(long double) = %lu\n", sizeof(long double));

	return 0;
}
