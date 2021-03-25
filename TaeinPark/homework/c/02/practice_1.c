#include <stdio.h>

int main(void)
{
	int i;
	int count=1;

	for(i=0;i<100;i++)
	{
		//2로 나누었을 때, 짝수는 숫자가 0으로 떨어진다.
		//그런데 0은 거짓이므로 if문 안으로 들어가지 않는다.
		//따라서 홀수 일 경우 나머지가 1이 되어 참이 되고
		//if문이 동작하여 그 숫자를 출력하게 된다.
		if(i%2)
		{
			printf("%d ",i);
			count++;
		}
		//홀수의 숫자를 계속 프린트 하다가 10번 이상 숫자를 찍을 경우
		//if문으로 들어가서 다음줄로 커서를 옮기고 count는 다시 제로 셋팅 한다.
		if(count>10)
		{
			printf("\n");
			count=1;
		}
	}
	printf("\n");

	return 0;
}

