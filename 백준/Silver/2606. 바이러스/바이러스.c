#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

bool roadmap[MAX + 1][MAX + 1] = { 0, };
int N, R;
int count = 0;
void input_data();
void virus(int num);

int main() {
	input_data();
	roadmap[1][1] = true;
	virus(1);
	printf("%d\n", count);
}

void input_data() {
	int from, to;
	(void)scanf("%d", &N);	(void)getchar();
	(void)scanf("%d", &R);	(void)getchar();
	for (int i = 0; i < R; ++i) {
		(void)scanf("%d %d", &from, &to);	(void)getchar();
		roadmap[from][to] = true;
		roadmap[to][from] = true;
	}
	return;
}

void virus(int num) {
	 
	for (int i = 1; i <= N; ++i) {
		if (roadmap[num][i] == true) {
			if (!roadmap[i][i]) {
				roadmap[i][i] = true;
				count++;
				//printf("count: %d\n", count);
				//printf("i: %d\n", i);
				virus(i);
			}
			
		}
	}
}