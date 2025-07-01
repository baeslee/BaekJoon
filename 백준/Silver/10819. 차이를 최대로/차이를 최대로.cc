// 03_BFS_DFS
// b10819. 차이를 최대로
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans;
int A[9];
int num[9];
int v[9];

void dfs(int n)
{
	if (n == N)
	{
		int sum = 0;
		for (int i = 1; i <= N-1; ++i)
			sum += abs(num[i]-num[i+1]);
		//if (N % 2 == 1)	sum += abs(num[N]);
		if (sum > ans)	ans = sum;
		
		return;
	}

	for (int j = 1; j <= N; ++j)
	{
		if (v[j] == 0)
		{
			num[n + 1] = A[j];
			v[j] = 1;
			dfs(n + 1);
			v[j] = 0;
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	dfs(0);
	cout << ans;

	return 0;
}