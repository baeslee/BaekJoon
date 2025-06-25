// 03_BFS_DFS
// p2468. 안전 영역

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int ans = 1, N;
int map[102][102];
int v[102][102];

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
void bfs(pair<int, int> p, int h)
{
	queue<pair<int, int>> q;
	q.push(p);
	v[p.first][p.second] = 1;
	
	pair<int, int> out;
	int r, c, cr, cc;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		r = out.first;
		c = out.second;
		for (int i = 0; i < 4; ++i)
		{
			cr = r + dr[i];
			cc = c + dc[i];
			if (map[cr][cc] > h && v[cr][cc] == 0)
			{
				q.push(make_pair(cr, cc));
				v[cr][cc] = 1;
			}
		}
	}
}
int main(void)
{
	cin >> N;
	int max = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];
			if (max < map[i][j])	max = map[i][j];
		}
	}

	int count;
	for (int h = 1; h < max; ++h)
	{
		count = 0;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (map[i][j] > h && v[i][j] == 0)
				{
					count++;
					bfs(make_pair(i, j), h);
				}
			}
		}
		if (count > ans) ans = count;
		// reset
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
				v[i][j] = 0;
		}
	}
	cout << ans;
	
	return 0;
}