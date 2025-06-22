#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;

int main(void) {
	(void)scanf("%d", &N);
	int sum;
	int count = 0;

	for (int i = 1; i <= N; ++i)
	{
		sum = 0;
		for (int j = i; sum < N; ++j)
		{
			sum += j;
			if (sum == N)
			{
				count++;
				break;
			}
		}
	}
	printf("%d", count);
	return 0;
}