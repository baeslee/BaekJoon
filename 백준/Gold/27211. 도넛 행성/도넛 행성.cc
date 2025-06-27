// 03_BFS_DFS
// p27211. 도넛 행성
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, ans;
int map[1000][1000];
int v[1000][1000];

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
void bfs(pair<int, int> p)
{
	queue <pair<int, int>> q;
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
			// 인덱스 보정
			cr = r + dr[i];
			if (cr == -1)	cr = N - 1;
			else cr %= N;
			cc = c + dc[i];
			if (cc == -1)	cc = M - 1;
			else cc %= M;

			if (map[cr][cc] == 0 && v[cr][cc] == 0)
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
	cin >> N >> M;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
			cin >> map[r][c];
	}
	// 완전탐색
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			if (map[r][c] == 0 && v[r][c] == 0)
			{
				ans++;
				bfs(make_pair(r, c));
			}
		}
	}
	cout << ans;

	return 0;
}