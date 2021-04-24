#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef를 통해 struct test를 test로 축약시킴
// 길게 쓰기 싫어서 적는다고 봐도 된다.
// 사실 좀 더 깊은 의미가 있는데
// 자바의 인터페이스 역할도 할 수 있긴하다.
typedef struct test test;

struct address
{
	char *city;
	char *street;
	int zipcode;
};

// { 10,     주소      } ----------> { 20, 주소 } -> { 30, 주소 }
//  int, 구조체 포인터                이하 동문        이하 동문

struct test
{
	int data;
	// 자료구조
	struct test *self_pointer;
	struct address addr;
	// 함수 포인터 - 다형성
	// 이 부분은 Lv3 소프트웨어 아키텍처링(설계) 파트에서 좀 더 상세하게 다룰 내용
	// 생산성을 증대시키면서 유지보수성을 함께 올릴 수 있는 방법은 무엇인가 ?
	// 100명 ~ 1000명 그 이상의 직원들이 함께 일을 한다면
	// 어떻게 해야 효율적이고 불필요한 시간 낭비를 절약할 수 있을것인가 ?
	// 이와 같은 문제에 대한 해결책이 사실 이 단순한 함수포인터에 녹아있다.
	// 레벨 2에서 소프트웨어 집중한 대규모 팀 프로젝트를 통해
	// 왜 이따구로 코딩을 하면 안되고 왜 문서를 요따구로 만들면 안되는지
	// 직접 부딪혀 보면서 파악하는 시간을 가지고
	// 이후 요 내용을 통해서 아 ~ 하 ? 하면 된다고 보시면 됩니다.

	// 숙제에서 함수 포인터는 패스해도 무방합니다.
	// 현재로서는 이 부분의 심도 있는 이해가 불가하기 때문
	// 어떤 흐름 때문에 사용한다는 파악하도록 한다.
	int *(* real)(int *, char ***, struct test *);
	void (* basic)(void);
};

void print_test(void)
{
	printf("print test\n");
}

void init_test_struct(struct test *sample, test *link)
{
	// -> 연산자: 간접 참조 연산으로 구조체 연산에만 활용됨
	// 구조체가 포인터로 주어졌을 경우 해당 포인터를 통해 구조체 필드에 접근한다면
	// -> 화살표 연산자를 사용해야함

	// . 연산자: 직접 참조 연산으로 마찬가지로 구조체에서 활용됨
	// 구조체가 포인터가 아닌 형태로 주어졌을 경우 사용함
	// 구조체 내부의 멤버 필드에 접근하기 위해 사용됨
	sample->data = rand() % 10 + 1;
	sample->self_pointer = link;

	char city[] = "Seoul";
	char street[] = "마포구 큰우물로 76";

	// 포인터 변수는 메모리를 할당해야 사용할 수 있다.
	// Heap 메모리는 일반 Stack이나 다른 메모리들과 다르게
	// 여러 프로세스들이 구동되면서 서로 얽힐 수도 있는데
	// +1을 통해 NULL 문자를 할당해두면
	// 뒤에 있는 내용을 붙어서 읽지 않고 끝이 어디인지 정확하게 알 수 있음
	sample->addr.city = (char *)malloc(strlen(city) + 1);
	// 위의 메모리 할당 없이 strcpy만 하는 경우 오류
	// sample->addr.city에 위의 city 배열을 복사한다.
	// string copy의 약자: strcpy
	strcpy(sample->addr.city, city);

	sample->addr.street = (char *)malloc(strlen(street) + 1);
	strcpy(sample->addr.street, street);

	sample->addr.zipcode = 12345;

	sample->real = NULL;
	sample->basic = print_test;
}

void print_test_struct(struct test sample)
{
	printf("data = %d\n", sample.data);
	printf("self_pointer = 0x%x\n", sample.self_pointer);
	printf("city = %s\n", sample.addr.city);
	printf("street = %s\n", sample.addr.street);
	printf("zipcode = %d\n", sample.addr.zipcode);
	printf("real = 0x%x\n", sample.real);
	// 함수의 이름도 결국 주소값이다.
	// 그러므로 포인터로 저장할 수 있다.
	// 이것이 함수 포인터다.
	printf("basic = 0x%x\n", sample.basic);
	printf("print_test = 0x%x\n", print_test);
}

void clear_malloc(test sample)
{
	free(sample.addr.city);
	free(sample.addr.street);
}

int main(void)
{
	// 구조체를 사용하는 방법
	// 1. struct를 적는다.
	// 2. 구조체 이름을 작성한다.
	// 3. 구조체 내부에서 사용할 데이터 타입과
	//    필드명(변수 같은것이지만 변수는 아님)을 작성한다.
	// 4. 활용할 때 struct 구조체명 변수명 형식으로 작성한다.
	// 1 ~ 3번까지는 새로운 데이터타입을 만든것이다.
	// 4번이 실제 활용하는 방식이며 결국 이것도 변수다.
	// 중요한 것은 C언어에서 구조체는
	// 우리만의 전용 데이터타입을 만드는 방식이란 것이다.
	struct test sample;
	// int sample
	// float sample
	// double sample
	// char *sample
	// char **sample
	// int *****sample
	// double ****************************sample
	test sample2;

	srand(time(NULL));

	init_test_struct(&sample, NULL);
	print_test_struct(sample);
	printf("\n");

	init_test_struct(&sample2, &sample);
	print_test_struct(sample2);
	printf("sample address = 0x%x\n", &sample);

	clear_malloc(sample);
	clear_malloc(sample2);

	return 0;
}
