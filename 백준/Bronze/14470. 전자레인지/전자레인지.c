#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int time = 0;
	int A, B, C, D, E;
	(void)scanf("%d", &A);
	(void)scanf("%d", &B);
	(void)scanf("%d", &C);
	(void)scanf("%d", &D);
	(void)scanf("%d", &E);

	if (A < 0)
	{
		time = A * (-1) * C + D;
		A = 0;
	}
	while (A != B)
	{
		time += E;
		A++;
	}
	printf("%d", time);
	return 0;
}