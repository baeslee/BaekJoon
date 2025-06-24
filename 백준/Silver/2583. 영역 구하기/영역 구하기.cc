// p2583. 영역 구하기
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int cnt, ex;
vector<int> ans;
int map[102][102];
int v[102][102];
typedef struct node
{
	int row;
	int col;
}node;
queue<node> q;

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
void bfs(int row, int col)
{
	node n = { row,col };
	q.push(n);
	v[row][col] = 1;
	ex = 1;

	int cr, cc;
	node out, temp;
	while (!q.empty()) {
		out = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			cr = out.row + dr[i];
			cc = out.col + dc[i];
			if (map[cr][cc] != 1 && v[cr][cc] == 0)
			{
				temp = { cr,cc };
				q.push(temp);
				v[cr][cc] = 1;
				ex++;
			}
		}
	}
	ans.push_back(ex);
	cnt++;
}
int main(void)
{
	int M, N, K;
	cin >> M >> N >> K;
	// padding
	for (int j = 0; j <= N + 1; ++j)
	{
		map[0][j] = 1;
		map[M + 1][j] = 1;
	}
	for (int i = 1; i <= M; ++i)
	{
		map[i][0] = 1;
		map[i][N + 1] = 1;
	}

	int cs, rs, ce, re;
	for (int i = 0; i < K; ++i)
	{
		cin >> cs >> rs >> ce >> re;
		for (int c = cs; c < ce; ++c)
		{
			for (int r = rs; r < re; ++r)
				map[r + 1][c + 1] = 1;
		}
	}
	
	for (int r = 1; r <= M; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			if (map[r][c] != 1 && v[r][c] == 0)
				bfs(r, c);
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << endl;
	for (int i = 0; i < cnt; ++i)
		cout << ans[i] << " ";
	
	return 0;
}