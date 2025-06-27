// 03_BFS_DFS
// p2589. 보물섬
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int row, col, ans;
int map[52][52];

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

void bfs(pair<int, int> p)
{
	int v[52][52] = { 0, };
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
			if (map[cr][cc] == 1 && v[cr][cc] == 0)
			{
				q.push(make_pair(cr, cc));
				v[cr][cc] = v[r][c] + 1;
			}
		}
	}
	ans = max(ans, v[r][c]);
}
int main(void)
{
	// 입력
	cin >> row >> col;
	string s;
	for (int i = 1; i <= row; ++i)
	{
		cin >> s;
		for (int j = 1; j <= col; ++j)
		{
			switch (s[j - 1])
			{
			case 'W':
				map[i][j] = 0;
				break;
			case 'L':
				map[i][j] = 1;
				break;
			}
		}
	}
	// 완전 탐색 + bfs
	for (int r = 1; r <= row; ++r)
	{
		for (int c = 1; c <= col; ++c)
		{
			if(map[r][c] == 1)
				bfs(make_pair(r, c));
		}
	}
	cout << ans - 1;

	return 0;
}