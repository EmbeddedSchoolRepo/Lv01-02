#include <stdio.h>

// #define을 통해서 특정 숫자를 아래와 같은 매크로 형태로 맵핑할 수 있다.
// 옵션들이 많아지면 숫자들이 많아지기 때문에
// 일일히 숫자로 기억하는 것 보다 옵션과 관련된 명칭으로 기억하는 것이 훨씬 편리하다.

#define BLDC		1
#define SERVO		2
#define CAMERA		3
#define AUDIO		4

int main(void)
{
	int num;

	printf("숫자를 입력하세요: ");
	scanf("%d", &num);

	// switch 문의 경우
	// 소괄호 내부의 num을 판정하고
	// case에 해당하는 내용이 있다면 해당 내용을 수행한다.
	// 이때 break를 만나지 않는다면 멈추지 않는다.
	switch (num)
	{
		case BLDC:
			printf("BLDC 모터 동작\n");
			// break;

		case SERVO:
			printf("SERVO 모터 구동\n");
			break;

		case CAMERA:
			printf("카메라 디바이스 활성화\n");
			break;

		case AUDIO:
			printf("오디오 코덱 활성화\n");
			break;
	}

	return 0;
}
