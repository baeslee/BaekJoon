// 04_백트래킹
// b15686. 치킨 배달
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int map[52][52];				// 사실 필요 없음
vector<pair<int, int>> home;	// 집 좌표 저장
vector<pair<int, int>> ch;		// 치킨 좌표 저장
pair<int, int> sel[13];			// 선택한 치킨
int v[13];						// 선택 치킨 방문표시
int N, M, ans=1000000;

void dfs(int n,int s)
{
	if (n == M)		// M개 선택
	{
		int sum = 0;
		int mn, r1, r2, c1, c2, dis;
		for (int i = 0; i < home.size(); ++i)	// 모든 집에 대해 반복
		{
			mn = 101;
			for (int j = 0; j < M; ++j)	// 한 집의 치킨거리 구하기
			{
				r1 = home[i].first;
				c1 = home[i].second;
				r2 = sel[j].first;
				c2 = sel[j].second;
				dis = abs(r1 - r2) + abs(c1 - c2);
				mn = min(mn, dis);		// M곳 중 가장 가까운 곳 = 치킨거리
			}
			sum += mn;					// 치킨거리 누적
		}
		if (sum < ans)	ans = sum;
		return;
	}

	for (int i = s; i < ch.size(); ++i)	// 치킨 M개 선택 dfs
	{
		if (v[i] == 0)
		{
			sel[n] = ch[i];
			v[i] = 1;
			dfs(n + 1,i);
			v[i] = 0;
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				ch.push_back(make_pair(i, j));
		}
	}
	dfs(0,0);
	cout << ans;
	
	return 0;
}