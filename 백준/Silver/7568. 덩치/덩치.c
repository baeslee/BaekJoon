#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct person
{
	int x;
	int y;
	int rank;
}person;

int N;
person p[50];

int main(void)
{
	(void)scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		(void)scanf("%d %d", &p[i].x, &p[i].y);
		p[i].rank = 1;
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
				continue;
			if (p[i].x > p[j].x && p[i].y > p[j].y)
			{
				++p[j].rank;
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		printf("%d ", p[i].rank);
	}
	return 0;
}