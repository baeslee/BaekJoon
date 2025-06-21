#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N;
	int count = 0;
	int temp;
	(void)scanf("%d", &N);
	if (N == 1) {
		printf("1");
		return 0;
	}

	for (int i = 2; i <= N; ++i)
	{
		temp = 0;
		for (int j = 1; j <= i; ++j)
		{
			if (i % j == 0)	temp++;
		}
		count += temp / 2;
		if (temp % 2 == 1)	count++;
	}

	printf("%d", count + 1);
	return 0;
}