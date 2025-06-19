#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int T, N, M;

double factorial(double n)
{
	if (n <= 1)
		return 1;
	else
		return (n * factorial(n - 1));
}
int main()
{
	double num = 0;
	(void)scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		(void)scanf("%d %d", &N, &M);

		num = factorial((double)M) / (factorial((double)(M - N)) * factorial((double)N));
		printf("%.0lf\n", num);
	}
	return 0;
}