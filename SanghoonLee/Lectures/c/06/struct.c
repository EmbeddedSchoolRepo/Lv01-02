#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address
{
	char *city;
	char *street;
	int zipcode;
};

struct test
{
	int data;
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

void init_test_struct(struct test *sample)
{
	sample->data = 7;
	sample->self_pointer = NULL;

	char city[] = "Seoul";
	char street[] = "마포구 큰우물로 76";

	sample->addr.city = (char *)malloc(strlen(city) + 1);
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

	init_test_struct(&sample);
	print_test_struct(sample);

	return 0;
}
