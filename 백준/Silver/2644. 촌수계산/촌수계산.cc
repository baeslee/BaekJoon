// p2644. 촌수계산
#include<iostream>
#include<vector>
using namespace std;

int ans, N, a, b;
int arr[101][101];
vector<int> q;
vector<int> v;

void bfs(int n)
{
	int num;
	q.push_back(n);
	v[n] = 1;
	while (!q.empty())
	{
		num = q.front();
		q.erase(q.begin());
		for (int i = 1; i <= N; ++i)
		{
			if (arr[num][b] == 1)
			{
				ans = arr[num][0] + 1;
				return;
			}
			if (arr[num][i] == 1 && v[i] != 1)
			{
				q.push_back(i);
				v[i] = 1;
				arr[i][0] = arr[num][0] + 1;
			}
		}
	}
	ans = -1;
}
int main(void)
{
	int m, x, y;
	cin >> N;
	v.resize(N + 1, 0);
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	bfs(a);
	cout << ans;
	return 0;
}