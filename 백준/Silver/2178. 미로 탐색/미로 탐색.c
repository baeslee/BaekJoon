#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 102

typedef struct node
{
	int row;
	int col;
}node;
int N, M;
int map[MAX][MAX];
int cost[MAX][MAX];
node queue[MAX * MAX];
int front, rear;
char str[MAX];

void input_data()
{
	(void)scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
	{
		(void)scanf("%s", str);	(void)getchar();
		for (int j = 1; j <= M; ++j)
		{
			map[i][j] = str[j - 1] - '0';
		}
	}
}
void push(int row, int col)
{
	queue[rear].row = row;
	queue[rear++].col = col;
}
node pop()
{
	return queue[front++];
}
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
void BFS()
{
	node temp;
	int cr, cc;
	while (front != rear)
	{
		temp = pop();
		//printf("r: %d, c: %d, cost: %d\n", temp.row, temp.col, cost[temp.row][temp.col]);
		for (int i = 0; i < 4; ++i)
		{
			cr = temp.row + dx[i];
			cc = temp.col + dy[i];
			if (map[cr][cc])
			{
				if (!cost[cr][cc] || cost[cr][cc] > cost[temp.row][temp.col] + 1)
				{
					push(cr, cc);
					cost[cr][cc] = cost[temp.row][temp.col] + 1;
				}
			}
		}
	}
}

int main()
{
	//(void)freopen("p2178_2.txt", "r", stdin);
	input_data();
	push(1, 1);
	cost[1][1] = 1;
	BFS();
	printf("%d\n", cost[N][M]);
	
	return 0;
}
