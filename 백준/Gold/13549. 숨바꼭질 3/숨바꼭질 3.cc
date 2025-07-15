// 분류: 너비 우선 탐색
// b13549. 숨바꼭질 3
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, K, ans = 100002;
int v[100001];
int cost[100001];

void bfs(int n, int step)
{
	queue<pair<int, int>> q;
	q.push(make_pair(n, step));
	v[n] = 1;

	pair<int, int> out;
	int pos, tm;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		pos = out.first;
		tm = out.second;
		if (pos == K)
		{
			if (tm < ans)
				ans = tm;
			continue;
		}
		// X-1 이동
		if (pos - 1 >= 0)
		{
			// 첫 방문
			if (v[pos-1] == 0)
			{
				v[pos - 1] = 1;
				cost[pos - 1] = tm + 1;
				q.push(make_pair(pos - 1, tm + 1));
			}
			// 첫 방문은 아닌데, 적은 비용
			else if (v[pos - 1] == 1 && cost[pos - 1] > tm + 1)
			{
				cost[pos - 1] = tm + 1;
				q.push(make_pair(pos - 1, tm + 1));
			}
		}
		// X+1 이동
		if (pos + 1 <= 100000)
		{
			// 첫 방문
			if (v[pos + 1] == 0)
			{
				v[pos + 1] = 1;
				cost[pos + 1] = tm + 1;
				q.push(make_pair(pos + 1, tm + 1));
			}
			// 첫 방문은 아닌데, 적은 비용
			else if (v[pos + 1] == 1 && cost[pos + 1] > tm + 1)
			{
				cost[pos + 1] = tm + 1;
				q.push(make_pair(pos + 1, tm + 1));
			}
		}
		// X*2 이동
		if (pos * 2 <= 100000)
		{
			// 첫 방문
			if (v[pos * 2] == 0)
			{
				v[pos * 2] = 1;
				cost[pos * 2] = tm;
				q.push(make_pair(pos * 2, tm));
			}
			// 첫 방문은 아닌데, 적은 비용
			else if (v[pos * 2] == 1 && cost[pos * 2] > tm)
			{
				cost[pos * 2] = tm;
				q.push(make_pair(pos * 2, tm));
			}
		}
	}
}

int main(void)
{
	cin >> N >> K;
	bfs(N, 0);
	cout << ans;
	
	return 0;
}
/*	
	X*2 이동은 비용이 없기에, 먼저 도달하더라도 비용이 클 수 있다.
	따라서 계속 확인하며 갱신 필요.
	비용을 저장하고, 비용이 갱신될 때 큐에 추가 삽입.
*/
// 틀린 이유
// 1. 완전 탐색되어야 하므로, bfs return이 아닌 continue
// 2. cost 배열 크기에 0 하나 누락...