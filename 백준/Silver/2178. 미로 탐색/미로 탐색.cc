#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int map[102][102];
int v[102][102];
int N, M, ans;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

void bfs(pair<int, int> p)
{
	queue<pair<int,int>> q;
	q.push(p);
	v[p.first][p.second] = 1;
	
	int r, c, cr, cc;
	pair<int, int> temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		r = temp.first;
		c = temp.second;
		for (int i = 0; i < 4; ++i)
		{
			cr = r + dr[i];
			cc = c + dc[i];
			if (cr == N && cc == M)
			{
				ans = v[r][c] + 1;
				return;
			}
			if (map[cr][cc] == 1 && v[cr][cc] == 0)
			{
				q.push(make_pair(cr, cc));
				v[cr][cc] = v[r][c] + 1;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		for (int j = 0; j < M; ++j)
		{
			map[i + 1][j + 1] = s[j] - '0';
		}
	}
	bfs(make_pair(1, 1));
	cout << ans;

	return 0;
}