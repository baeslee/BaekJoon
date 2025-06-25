// 03_BFS_DFS
// p7562. 나이트의 이동
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int ans, T, I;
int rs, cs, re, ce;
int v[300][300];

int dr[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dc[8] = { -2,-1,1,2,2,1,-1,-2 };
void bfs(pair<int, int> p)
{
	queue<pair<int, int>> q;
	q.push(p);
	v[p.first][p.second] = 0;

	pair<int, int> out;
	int r, c, cr, cc;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		r = out.first;
		c = out.second;
		if (r == re && c == ce)
		{
			ans = v[r][c];
			return;
		}
		for (int i = 0; i < 8; ++i)
		{
			cr = r + dr[i];
			cc = c + dc[i];
			if (cr < 0 || cr >= I || cc < 0 || cc >= I)	continue;
			if (v[cr][cc] == 0)
			{
				q.push(make_pair(cr, cc));
				v[cr][cc] = v[r][c] + 1;
			}
		}

	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> I;
		cin >> rs >> cs;
		cin >> re >> ce;
		bfs(make_pair(rs, cs));
		cout << ans << endl;
		// reset
		ans = 0;
		for (int r = 0; r < I; ++r)
		{
			for (int c = 0; c < I; ++c)
				v[r][c] = 0;
		}
	}
	
	return 0;
}