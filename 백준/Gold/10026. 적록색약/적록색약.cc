// 03_BFS_DFS
// p10026. 적록색약
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int map[100][100];
int v[100][100];
int N, ans;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
void bfs1(pair<int, int> p)
{
	queue<pair<int, int>> q;
	q.push(p);
	v[p.first][p.second] = 1;

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
			if (cr < 0 || cr >= N || cc < 0 || cc >= N)	continue;
			if (map[cr][cc] == map[r][c] && v[cr][cc] == 0)
			{
				q.push(make_pair(cr, cc));
				v[cr][cc] = 1;
			}
		}
	}
}
void bfs(pair<int, int> p)
{
	queue<pair<int, int>> q;
	q.push(p);
	v[p.first][p.second] = 1;

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
			if (cr < 0 || cr >= N || cc < 0 || cc >= N)	continue;
			if (map[cr][cc] == map[r][c] && v[cr][cc] == 0)
			{
				q.push(make_pair(cr, cc));
				v[cr][cc] = 1;
			}
		}
	}
}
int main(void)
{
	// 입력
	cin >> N;
	string s;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		for (int j = 0; j < N; ++j)
		{
			switch (s[j])
			{
			case 'R':
				map[i][j] = 1;
				break;
			case 'G':
				map[i][j] = 2;
				break;
			case 'B':
				map[i][j] = 3;
				break;
			}
		}
	}
	// 정상인
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (v[i][j] == 0)
			{
				ans++;
				bfs(make_pair(i, j));
			}
		}
	}
	cout << ans << " ";
	// reset
	ans = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			v[i][j] = 0;
			if (map[i][j] == 2)	map[i][j] = 1;
		}
	}
	// 색약
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (v[i][j] == 0)
			{
				ans++;
				bfs(make_pair(i, j));
			}
		}
	}
	cout << ans;

	return 0;
}