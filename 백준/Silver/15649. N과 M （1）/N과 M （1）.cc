#include<iostream>
#include<vector>
using namespace std;

int N, M;
int lst[8 + 1];
int v[8 + 1];

void bfs(int n)
{
	// [1] 종료조건 n == M (선택 개수)
	if (n == M)
	{
		// 출력
		for (int i = 1; i <= M; ++i)
			cout << lst[i] << " ";
		cout << "\n";
		return;
	}

	for (int j = 1; j <= N; ++j)
	{
		if (v[j] == 0)
		{
			lst[n + 1] = j;
			v[j] = 1;
			bfs(n + 1);
			v[j] = 0;
		}
	}
}

int main(void)
{
	cin >> N >> M;
	bfs(0);

	return 0;
}