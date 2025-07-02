// 04_백트래킹
// b130231. ABCDE
#include<iostream>
#include<vector>
using namespace std;

int N, M, ans;
vector<int> map[2000];
int v[2000];

void dfs(int n, int dep)
{
	if (dep == 5)
	{
		ans = 1;
		return;
	}

	for (int j = 0; j < map[n].size(); ++j)
	{
		if (v[map[n][j]] == 0)
		{
			v[map[n][j]] = 1;
			dfs(map[n][j], dep + 1);
			v[map[n][j]] = 0;
			if (ans == 1) return;
		}
	}
}

int main(void)
{
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for (int i = 0; i < N; ++i)
	{
		if (!map[i].empty())
		{
			v[i] = 1;
			dfs(i,1);
			v[i] = 0;

			if (ans == 1)break;
		}
	}
	cout << ans;

	return 0;
}