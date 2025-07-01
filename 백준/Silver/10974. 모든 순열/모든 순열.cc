// 04_백트래킹
// b10974. 모든 순열
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int num[9];
int v[9];

void dfs(int n)
{
	if (n == N)
	{
		for (int i = 1; i <= N; ++i)
			cout << num[i] << " ";
		cout << "\n";
		
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (v[i] == 0)
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
	cin >> N;
	dfs(0);

	return 0;
}