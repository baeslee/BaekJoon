#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int X, N;
	int sum = 0;
	int a, b;
	
	(void)scanf("%d", &X);
	(void)scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		(void)scanf("%d %d", &a, &b);
		sum += a * b;
	}
	if (X == sum)
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
}