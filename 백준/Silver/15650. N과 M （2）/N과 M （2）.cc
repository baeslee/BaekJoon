// 04_백트래킹
// b15650. N과 M (2)
#include<iostream>
using namespace std;

int num[9];
int v[9];
int N, M;

void dfs(int n)
{
	if (n == M)
	{
		for (int i = 1; i <= M; ++i)
			cout << num[i] << " ";
		cout << endl;

		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (v[i] == 0 && i > num[n])
		{
			num[n + 1] = i;
			v[i] = 1;
			dfs(n + 1);
			v[i] = 0;
		}
	}
}

int main(void)
{
	cin >> N >> M;
	dfs(0);

	return 0;
}