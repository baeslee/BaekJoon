#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int main(void) {
	int N, min;
	int* ary = 0;
	scanf("%d", &N);
	ary = (int*)malloc(N * sizeof(int));
	if (ary == 0)	exit(1);

	for (int i = 0;i<N;++i){
		scanf("%d", ary + i);
	}
	for (int i = 0; i < N-1; ++i) {
		min = i;
		for (int j = i + 1; j < N; ++j)
			if (*(ary + j) < *(ary + min))
				min = j;
		if (i != min) {
			swap(ary + i, ary+min);
		}
	}
	for (int i = 0; i < N; ++i)
		printf("%d\n", *(ary + i));
	
	return 0;
}