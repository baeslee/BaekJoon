#include<iostream>
#include<queue>;
using namespace std;

int n, m, ans;
int s, e;
int map[101][101];
int v[101];

void bfs(int num) {
	queue<int> q;
	q.push(num);
	v[num] = 1;
	
	int out;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		for (int i = 1; i <= n; ++i)
		{
			if (map[out][e] == 1)
			{
				ans = map[out][0] + 1;
				return;
			}
			if (map[out][i] == 1 && v[i] == 0)
			{
				q.push(i);
				v[i] = 1;
				map[i][0] = map[out][0] + 1;
			}
		}
	}
	ans = -1;
}

int main(void)
{
	cin >> n;
	cin >> s >> e;
	cin >> m;
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	bfs(s);
	cout << ans;
	
	return 0;
}