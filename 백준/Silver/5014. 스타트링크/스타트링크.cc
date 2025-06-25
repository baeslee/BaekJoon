// 03_BFS_DFS
// p7562. 나이트의 이동

// 최고층 F
// 현재층 S
// 목표층 G

#include<iostream>
#include<queue>
using namespace std;

int F, S, G, U, D;
int v[1000001];

int main(void)
{
	cin >> F >> S >> G >> U >> D;
	
	queue <int> q;
	q.push(S);
	v[S] = 1;
	int out;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		if (out == G)
		{
			cout << v[out] - 1;
			return 0;
		}
		if (out + U > 0 && out + U <= F && v[out + U] == 0)
		{
			q.push(out + U);
			v[out + U] = v[out] + 1;
		}
		if (out - D > 0 && out - D <= F && v[out - D] == 0)
		{
			q.push(out - D);
			v[out - D] = v[out] + 1;
		}
	}
	cout << "use the stairs";
	return 0;
}