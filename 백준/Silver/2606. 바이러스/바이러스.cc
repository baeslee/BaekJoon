#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int map[101][101];
int v[101];
int N, M, ans;

void bfs(int n)
{
	queue <int> q;
	v[n] = 1;
	q.push(n);

	int out;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		for (int j = 1; j <= N; ++j)
		{
			if (map[out][j] == 1 && v[j] == 0)
			{
				ans++;
				v[j] = 1;
				q.push(j);
			}
		}
	}
}

int main(void)
{
	cin >> N;
	cin >> M;
	int r, c;
	for (int i = 0; i < M; ++i)
	{
		cin >> r >> c;
		map[r][c] = 1;
		map[c][r] = 1;
	}
	bfs(1);
	cout << ans;

	return 0;
}