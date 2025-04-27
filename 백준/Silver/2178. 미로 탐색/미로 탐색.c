#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

// 백준 2178번. 미로탐색 (BFS)
#if 01
#define MAX_N (102)
typedef struct _node {
	int r;
	int c;
	int cnt;
}Node;

Node* queue;
int (*map)[MAX_N];
int (*check)[MAX_N];
int front, rear;
int N, M;

void EnQueue(int r, int c, int cnt) {
	check[r][c] = 1;
	queue[rear].r = r;
	queue[rear].c = c;
	queue[rear].cnt = cnt;
	rear++;
}
Node DeQueue() {
	return queue[front++];
}

void input_data(void) {
	char str[MAX_N] = { 0 };
	(void)scanf("%d %d", &N, &M);
	queue = (Node*)calloc(N * M,sizeof(Node));
	map = (int(*)[MAX_N])calloc(N+2,sizeof(int[MAX_N]));
	check = (int(*)[MAX_N])calloc(N + 2, sizeof(int[MAX_N]));
	if (!queue || !map || !check)	exit(0);

	for (int i = 1; i <= N; ++i) {
		(void)scanf("%s", str + 1);
		for (int j = 1; j <= M; ++j) {
			map[i][j] = str[j] - '0';
		}
	}
}

void print_arr(int (*arr)[MAX_N]) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void destroy(void) {
	free(queue);
	free(map);
	free(check);
}

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int miro() {
	Node curr = { 0 };
	int cr, cc;
	rear = front = 0;
	EnQueue(1, 1, 1);

	while (front != rear) {
		curr = DeQueue();
		for (int i = 0; i < 4; ++i) {
			cr = curr.r + dr[i];
			cc = curr.c + dc[i];
			if (N == cr && M == cc) {
				return curr.cnt+1;
			}
			if (map[cr][cc] && !check[cr][cc]) {
				EnQueue(cr, cc, curr.cnt+1);
			}
		}
	}
	// N, M 위치에 도달하지 못한 상황
	return -1;
}

int main() {
	int n = 1;
	//(void)freopen("p2178.txt", "r", stdin);
	//(void)scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		input_data();
		//print_arr(map);
		printf("%d\n", miro());
		//print_arr(map);
		destroy();
	}
	
	return 0;
}
#endif