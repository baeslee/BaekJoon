// 03_BFS_DFS
// p12851. 숨바꼭질 2
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, K, ans, most;
int v[100001];
int cost[100001];

int main(void)
{
	cin >> N >> K;
	queue<int> q;
	q.push(N);
	
	int out;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		if (out == K)
		{
			ans++;
			continue;
		}
		if (out - 1 >= 0 && out - 1 <= 100000)
		{
			if (cost[out - 1] == 0)
			{
				q.push(out - 1);
				cost[out - 1] = cost[out] + 1;
			}
			else if (cost[out - 1] == cost[out] + 1)
			{
				q.push(out - 1);
			}
		}
		
		if (out + 1 >= 0 && out + 1 <= 100000)
		{
			if (cost[out + 1] == 0)
			{
				q.push(out + 1);
				cost[out + 1] = cost[out] + 1;
			}
			else if (cost[out + 1] == cost[out] + 1)
			{
				q.push(out + 1);
			}
		}

		if (out * 2 <= 100000)
		{
			if (cost[out * 2] == 0)
			{
				q.push(out * 2);
				cost[out * 2] = cost[out] + 1;
			}
			else if (cost[out * 2] == cost[out] + 1)
			{
				q.push(out * 2);
			}
		}
	}
	cout << cost[K] << endl << ans;

	return 0;
}