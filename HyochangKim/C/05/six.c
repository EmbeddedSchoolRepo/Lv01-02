#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORK 3
#define YEAR 10
#define PAY_MAX 3600
#define PAY_MIN 2400
#define RISE_MAX 10
#define RISE_MIN 1

int main(void) {
	double worker_num[WORK], rise_rate;
	int x , y;

	

	
	for(x = 0; x < WORK; x++)
	{
		worker_num[x] = rand() % (PAY_MAX - PAY_MIN + 1) + PAY_MIN;
		printf("신입 기본급 [%d] : %lf\n", x, worker_num[x]);
	}


	for(y = 0; y < 10; y++)
	{
		rise_rate = (rand() % (RISE_MAX - RISE_MIN) + RISE_MIN)*0.01;
		
		printf("rise rate의 값 %lf\n", rise_rate);
		
		worker_num[0] += (worker_num[0] * rise_rate);
		worker_num[1] += (worker_num[1] * rise_rate);
		worker_num[2] += (worker_num[2] * rise_rate);
		
	}
	printf("\n");
	
	printf("10년 후 직원1 연봉 : %lf\n", worker_num[0]);
	printf("10년 후 직원2 연봉 : %lf\n", worker_num[1]);
	printf("10년 후 직원3 연봉 : %lf\n", worker_num[2]);


}
