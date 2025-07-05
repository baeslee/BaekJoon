#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	int N, ans = 1;

	int map[100001];
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> map[i];

	int highest = map[N-1];
	for (int i = N-2; i >=0; --i)
		if (map[i] > highest)
		{
			highest = map[i];
			ans++;
		}
	cout << ans;

	return 0;
}
//맨끝부터 볼 때, 더 높은게 등장하면 highest 바뀌는걸 간과했다.