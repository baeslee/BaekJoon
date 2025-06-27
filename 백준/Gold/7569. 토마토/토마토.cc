// 03_BFS_DFS
// p7569. 토마토
#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

int N, M, H;
int ans, remain;
int map[100][100][100];
queue<tuple<int, int, int>> q;

int dh[6] = { 1,-1,0,0,0,0 };
int dr[6] = { 0,0,1,-1,0,0 };
int dc[6] = { 0,0,0,0,1,-1 };

void bfs()
{
	tuple<int, int, int> out;
	int h, r, c, ch, cr, cc;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		h = get<0>(out);
		r = get<1>(out);
		c = get<2>(out);
		for (int i = 0; i < 6; ++i)
		{
			ch = h + dh[i];
			cr = r + dr[i];
			cc = c + dc[i];
			if (ch < 0 || cr < 0 || cc < 0 || ch >= H || cr >= N || cc >= M)	continue;
			if (map[ch][cr][cc] == 0)
			{
				q.push(make_tuple(ch, cr, cc));
				map[ch][cr][cc] = map[h][r][c] + 1;
				remain--;
			}
		}
	}
	if (remain == 0)
		ans = map[h][r][c] - 1;
	else ans = -1;
}
int main(void)
{
	// 입력
	cin >> M >> N >> H;
	for (int h = 0; h < H; ++h)
	{
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				cin >> map[h][r][c];
				if (map[h][r][c] == 0)	remain++;
			}
		}
	}
	// bfs
	for (int h = 0; h < H; ++h)
	{
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				if (map[h][r][c] == 1)
				{
					q.push(make_tuple(h, r, c));
				}
			}
		}
	}
	bfs();
	cout << ans;
	
	return 0;
}