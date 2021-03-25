// 피보나치 수열 1(첫번째), 1(두번째), 2, 3, 5, 8, 13, 21, ...
// n항의 값이 (n-1),(n-2)의 합으로 이루어 진다.
// 예를 들어 t1, t2가 0번째, 1번째 항 이라면 더해진 값은 2번째 항이 되며
// 3번째 항은 1번째, 2번째 항의 합이 된다.
// next = t1 + t2;
// t1 = t2;
// t2 = next;

#include <stdio.h>

int main(void)
{
	int i, n, next;
	// 1번째 값
	int t1 = 1;
	// 2번째 값
	int t2 = 1;

	printf("출력할 피보나치 수열의 항의 N항 : ");
	// 몇 번째 항까지 출력 할 건지 입력
	scanf("%d",&n);
	printf("피보나치 수열 : %d\n",n);

	// N 항까지 for문 돌려서 출력
	for(i=1; i<n; i++)
	{
		printf("%d ", t1);
		next = t1 + t2;
		t1 = t2;
		t2 = next;
	}
	printf("%d ", t1);
	printf("\n");
	printf("따라서 N 번째 항의 값은 : %d !\n ", t1);

	return 0;
}	


