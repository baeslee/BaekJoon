// 03_BFS_DFS
// p7576. 토마토
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int M, N;
int map[1000][1000];
int remain, ans;
queue <pair<int, int>> q;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
void bfs()
{
	int r, c, cr, cc;
	pair<int, int> out;
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
			if (cr < 0 || cr >= N || cc < 0 || cc >= M) continue;
			if (map[cr][cc] == 0)
			{
				q.push(make_pair(cr, cc));
				map[cr][cc] = map[r][c] + 1;
				remain--;
			}
		}
	}
}

int main(void)
{
	cin >> M >> N;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == 0)	remain++;
		}
	}
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			if(map[r][c]==1)
				q.push(make_pair(r,c));
		}
	}
	bfs();
	if (remain > 0)
	{
		cout << -1;
		return 0;
	}
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			ans = max(map[r][c], ans);
		}
	}
	cout << ans - 1;
	return 0;
}