// 03_BFS_DFS
// p2667. 단지번호붙이기
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int ans, N;
int map[27][27];
int v[27][27];
vector <int> ex;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
void bfs(pair<int, int> p)
{
	int n = 1;
	queue<pair<int, int>> q;
	q.push(p);
	v[p.first][p.second] = 1;

	pair<int,int> out;
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
				q.push(make_pair(cr, cc));
				v[cr][cc] = 1;
				++n;
			}
		}
	}
	ex.push_back(n);
	ans++;
}

int main(void)
{
	cin >> N;
	string s;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		for (int j = 0; j < N; ++j)
			map[i + 1][j + 1] = s[j] - '0';
	}
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (map[i][j] == 1 && v[i][j] == 0)
			{
				bfs(make_pair(i, j));
			}
		}
	}
	sort(ex.begin(), ex.end());
	cout << ans << endl;
	for (int i = 0; i < ans; ++i)
		cout << ex[i] << endl;

	return 0;
}