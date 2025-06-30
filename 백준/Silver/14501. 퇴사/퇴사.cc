// 04_백트래킹
// b14501. 퇴사
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans;
int T[16], P[16];
int sum;

void dfs(int n)
{
	if (n == N)
	{
		ans = max(ans, sum);
		return;
	}

	// 선택 O
	if (n + T[n+1] <= N)
	{
		sum += P[n+1];
		dfs(n + T[n+1]);
		sum -= P[n+1];
	}
	// 선택 X
	dfs(n + 1);
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> T[i] >> P[i];
	dfs(0);
	cout << ans;

	return 0;
}
// dfs 조건에서, N과 M 문제처럼 반복문 돌리니 상담일수만큼 넘어가지 않았다.
// 상담일수만큼 건너뛰어야하므로 반복문이 필요없다.