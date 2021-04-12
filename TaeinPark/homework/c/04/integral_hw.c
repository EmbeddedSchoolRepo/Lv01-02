#include <stdio.h>

// 우리가 미분 하는 혹은 적분하는 구간을 몇 개의 구간으로 나눌 것인가
#define SAMPLE_NUM			1000000

// x좌표에 두 점은   x,    x+h
// y좌표에 두 점은 f(x), f(x+h)
// 미분의 정의 limit h -> 0
// 컴퓨터에서는 미분을 표현할 수 있는가 ????
// 근사치로 표현할 수 있지만 정밀한 정의는 사실상 불가능하다.
// 그렇기 때문에 수학적(이론적)으로는 아주 정밀한 미적분이 가능하지만
// 컴퓨터는 오차를 안고 가야하기 때문에 연산 자체에 항상 오차를 고려해야만 한다.
// 이것을 가능하게 만들어주는 방식이 수치해석(Numerical Analysis)이라고 한다.

// 실제로는 위와 같은 미소값들을 통해
// 밑변 x 높이를 Sigma 하여 누산하는 방식이 결국 적분이다.
// 이것을 컴퓨터로 구현한다면 결국 다중 곱셈과 다중 덧셈으로 구성될 것이다.
float integral(float start, float end)
{
	int i;
	float criteria, dx, y, area, sum = 0;

	criteria = (end - start) / SAMPLE_NUM;

	for(i = 0; i < SAMPLE_NUM; i++)
	{
		dx = start + criteria * i;
		// 현재 우리가 보고 있는 원 함수가 x^2 이기 때문이다.
		y = dx * dx;
		// 너무 낮은 숫자를 사용할 경우 더 이상 표현할 수 없어서 underflow가 발생한다.
		// 이렇게 되면 잘못된 결과를 유발할 수 있으므로 적당히 중간 중간 값을 확인하며
		// 오차를 최소화시킬 수 있는 방식을 찾아야 할 것이다.
		area = criteria * y;
		sum += area;
	}

	return sum;
}

int main(void)
{
	float res;

	printf("1 ~ 3까지 x^2에 대한 정적분을 수행합니다.\n");

	res = integral(1.0f, 3.0f);
	printf("res = %f\n", res);

	return 0;
}


