// 03_BFS_DFS
// b10819. 영재의 시험
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int ans;
int num[11];
int a[11];

void dfs(int n)
{
	if (n == 10)
	{
		int score = 0;
		for (int i = 1; i <= 10; ++i)
			if (num[i] == a[i])	score++;
		if(score>=5)	ans++;

		return;
	}

	for (int i = 1; i <= 5; ++i)
	{
		if (n < 2 || !(num[n - 1] == num[n] && num[n] == i))
		{
			num[n + 1] = i;
			dfs(n + 1);
		}
	}
}

int main(void)
{
	for (int i = 1; i <= 10; ++i)
		cin >> a[i];
	dfs(0);
	cout << ans;
	
	return 0;
}