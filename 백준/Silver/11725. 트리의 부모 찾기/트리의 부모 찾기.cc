#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> map[100001];
int v[100001];
int N;

void bfs(int n)
{
	queue<int> q;
	q.push(n);
	v[n] = 1;

	int out;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		for (int i = 0; i < map[out].size(); ++i)
		{
			int next = map[out][i];
			if (v[next] == 0)
			{
				v[next] = out;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	cin >> N;
	int a, b;
	for (int i = 0; i < N-1; ++i)
	{
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i <= N; ++i)
		cout << v[i] << "\n";

	return 0;
}
// visited 배열에 부모 노드 번호 삽입