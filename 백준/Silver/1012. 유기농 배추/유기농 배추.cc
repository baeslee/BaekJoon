// 분류: 너비 우선 탐색
// b1012. 유기농 배추
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int T, N, M, K, ans;
int map[52][52];
int v[52][52];

// 입력부
void input(void)
{
	int Y, X;
	cin >> M >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		cin >> X >> Y;
		map[Y + 1][X + 1] = 1;
	}
}

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

// 영역 색칠
void bfs(pair<int, int> p)
{
	queue<pair<int, int> > q;
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
			if (map[cr][cc] == 1 && v[cr][cc] == 0)
			{
				v[cr][cc] = 1;
				q.push(make_pair(cr, cc));
			}
		}
	}
}

// 초기화
void reset(void)
{
	ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			map[i][j] = 0;
			v[i][j] = 0;
		}
	}
}

int main(void)
{
	
	cin >> T;
	
	for (int t = 0; t < T; ++t)
	{
		input();
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if (map[i][j] == 1 && v[i][j] == 0)
				{
					ans++;
					bfs(make_pair(i, j));
				}
			}
		}
		cout << ans << "\n";
		reset();
	}
	
	return 0;
}
// 단순 영역 개수 구하는 문제.
// 큐 pop 까먹음. -> 무한루프 발생