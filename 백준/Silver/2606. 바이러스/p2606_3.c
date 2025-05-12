#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX 101
int array[MAX][MAX];
int visited[MAX];
int count, N, M;
int queue[100];
int front, rear;

void input_data()
{
	(void)scanf("%d", &N);
	(void)scanf("%d", &M);
	int com1, com2;
	for (int i = 0; i < M; ++i)
	{
		(void)scanf("%d %d", &com1, &com2);
		array[com1][++array[com1][0]] = com2;
		array[com2][++array[com2][0]] = com1;
	}
}
void push(int data)
{
	visited[data] = 1;
	queue[rear++] = data;
}
int pop()
{
	return queue[front++];
}
void infection()
{
	int check;
	while (front != rear)
	{
		int temp = pop();
		while (array[temp][array[temp][0]])
		{
			check = array[temp][array[temp][0]--];
			if (!visited[check])
			{
				push(check);
				++count;
			}
		}
	}
}

int main()
{
	//(void)freopen("p2606.txt", "r", stdin);
	input_data();
	push(1);
	infection();
	printf("%d\n", count);
}
