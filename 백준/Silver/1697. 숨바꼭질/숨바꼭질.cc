// 03_BFS_DFS
// p1697. 숨바꼭질
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int ans, N, K;
int v[100001];

void bfs(int n)
{
	queue<int> q;
	q.push(n);
	int out;

	while (!q.empty())
	{
		out = q.front();
		q.pop();
		if (out - 1 == K || out + 1 == K || out * 2 == K)
		{
			ans = v[out] + 1;
			return;
		}
		if (out - 1 >= 0 && out - 1 <= 100000 && v[out - 1] == 0)
		{
			q.push(out - 1);
			v[out - 1] = v[out] + 1;
		}
		if (out + 1 >= 0 && out + 1 <= 100000 && v[out + 1] == 0)
		{
			q.push(out + 1);
			v[out + 1] = v[out] + 1;
		}
		if (out * 2 >= 0 && out * 2 <= 100000 && v[out * 2] == 0)
		{
			q.push(out * 2);
			v[out * 2] = v[out] + 1;
		}
	}

}

int main()
{
	cin >> N >> K;
	if (N == K)
	{
		cout << 0;
		return 0;
	}
	bfs(N);
	cout << ans;
	
	return 0;
}