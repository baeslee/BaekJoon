#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N, A, B;
	(void)scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		(void)scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", i + 1, A + B);
	}

	return 0;
}