#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int N, M, ans;
int map[102][102];
int v[102][102];

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0, 1,-1 };
void bfs(pair<int, int> p)
{
	queue <pair<int, int>> q;
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
		if (r == N && c == M)
		{
			ans = map[r][c];
			return;
		}
		for (int i = 0; i < 4; ++i)
		{
			cr = r + dr[i];
			cc = c + dc[i];
			if (map[cr][cc] > 0 && v[cr][cc] == 0)
			{
				q.push(make_pair(cr, cc));
				v[cr][cc] = 1;
				map[cr][cc] = map[r][c] + 1;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	string str;
	for (int i = 1; i <= N; ++i)
	{
		cin >> str;
		for (int j = 1; j <= str.size(); ++j)
			map[i][j] = str[j - 1] - '0';
	}

	bfs(make_pair(1, 1));
	cout << ans;

	return 0;
}