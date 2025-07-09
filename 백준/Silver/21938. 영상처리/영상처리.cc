#include<iostream>
#include<queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M, T, ans;
tuple<int, int, int> map[1002][1002];
int v[1002][1002];

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

void bfs(pair<int,int> p)
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
			if (cr <= 0 || cc <= 0 || cr > N || cc > M)	continue;
			int red = get<0>(map[cr][cc]);
			int green = get<1>(map[cr][cc]);
			int blue = get<2>(map[cr][cc]);
			if ((red + green + blue)/3 >= T && v[cr][cc] == 0)
			{
				q.push(make_pair(cr, cc));
				v[cr][cc] = 1;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	int R, G, B;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> R >> G >> B;
			map[i][j] = make_tuple(R, G, B);
		}
	}
	cin >> T;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int r = get<0>(map[i][j]);
			int g = get<1>(map[i][j]);
			int b = get<2>(map[i][j]);
			if ((r + g + b)/3 >= T && v[i][j] == 0)
			{
				ans++;
				bfs(make_pair(i,j));
			}
		}
	}
	cout << ans;
	return 0;
}