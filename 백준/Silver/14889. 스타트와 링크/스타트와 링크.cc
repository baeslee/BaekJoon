// 04_백트래킹
// b14889. 스타트와 링크
#include<iostream>
#include<algorithm>
using namespace std;

int N, ans=1000000;
int S[21][21];
int v[21];
int cnt;

void dfs(int n)
{
	if (n > N)	return;
	if (cnt == N / 2)
	{
		int sum1 = 0, sum2 = 0;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (v[i] == 1 && v[j] == 1)
					sum1 += S[i][j];
				else if (v[i] == 0 && v[j] == 0)
					sum2 += S[i][j];
			}
		}
		if (abs(sum1 - sum2) < ans)
			ans = abs(sum1 - sum2);
		return;
	}
	cnt++;
	v[n + 1] = 1;
	dfs(n + 1);
	v[n + 1] = 0;
	cnt--;

	dfs(n + 1);
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cin >> S[i][j];
	}
	dfs(0);
	cout << ans;

	return 0;
}
