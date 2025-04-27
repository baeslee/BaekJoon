#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_MAX (1000+1)
#define M_MAX (10000)

typedef struct node 
{
	int data;
	struct node* next;
}node;

node array[N_MAX];
bool visited[N_MAX];
int list[M_MAX];
int front, rear, flag;
int N, M, V;

void create_node(int pos, int data)
{
	node* curr = array + pos;
	if (!curr->next)
	{
		curr->next = (node*)malloc(sizeof(node));
		if (!curr->next)	exit(0);
		curr->next->data = data;
		curr->next->next = NULL;
		return;
	}
	while (curr->next && data > curr->next->data)
	{
		curr = curr->next;
	}
	node* temp = curr->next;
	curr->next = (node*)malloc(sizeof(node));
	if (!curr->next)	exit(0);
	curr->next->data = data;
	curr->next->next = temp;
}
void input_data() 
{
	(void)scanf("%d %d %d", &N, &M, &V);
	int from, to;
	for(int i=0;i<M;++i)
	{
		(void)scanf("%d %d", &from, &to);
		create_node(from, to);
		create_node(to, from);
	}
}
void push(int data)
{
	list[rear++] = data;
	visited[data] = true;
	//printf("push: %d\n", list[rear - 1]);
}
int pop(int flag)
{
	int temp;
	if (!flag)	// 스택 DFS
	{
		temp = list[--rear];
		printf("%d ", temp);
	}
	else // 큐 BFS
	{
		temp = list[front++];
		printf("%d ", temp);
	}

	return temp;
}
void DFS()
{
	int temp;
	node* curr;
	while (rear)
	{
		temp = pop(flag);
		//visited[temp] = true;
		curr = &array[temp];
		while (curr->next)
		{
			curr = curr->next;
			if (!visited[curr->data])
			{
				push(curr->data);
				DFS();
			}
		}

	}
}
void DFS_to_BFS()
{
	for (int i = 1; i <= N; ++i)
	{
		visited[i] = false;
	}
	flag = 1;
	printf("\n");
}
void BFS()
{
	int temp;
	node* curr;
	while (front != rear)
	{
		temp = pop(flag);
		visited[temp] = true;
		curr = &array[temp];
		while (curr->next)
		{
			curr = curr->next;
			if (!visited[curr->data])
			{
				push(curr->data);
			}
		}
	}
}

int main(void) 
{
	//(void)freopen("p1260.txt", "r", stdin);
	input_data();
	push(V);
	//printf("DFS start\n");
	DFS();
	//printf("DFS end\n");
	DFS_to_BFS();
	push(V);
	//printf("BFS start\n");
	BFS();
	//printf("BFS end\n");

	return 0;
}