// 03_BFS_DFS
// p9205. 맥주 마시면서 걸어가기
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


#define fix 32768	// x,y 범위에 음수가 있으므로 양수화 시킨다.
typedef unsigned short us;

int t, n;
string ans;
us rs, cs, re, ce, rr, cc;
vector<pair<us, us>> map;
vector<pair<us, us>> v;

void bfs(pair<us, us> p)
{
	queue<pair<us, us>> q;
	q.push(p);
	v.push_back(p);

	pair<us, us> out;
	us r, c;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		r = out.first;
		c = out.second;
		if (r == re && c == ce)
		{
			ans = "happy";
			return;
		}
		for (int i = 0; i < n + 1; ++i)
		{
			if (find(v.begin(), v.end(), map[i]) == v.end())
			{
				if ((max(r, map[i].first) - min(r, map[i].first)) + (max(c, map[i].second) - min(c, map[i].second)) <= 1000)
				{
					q.push(map[i]);
					v.push_back(map[i]);
				}
			}
		}
	}
	ans = "sad";
}
int main(void)
{
	// 입력
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		cin >> rs >> cs;
		rs += fix;
		cs += fix;
		for (int j = 0; j < n; ++j)
		{
			cin >> rr >> cc;
			rr += fix;
			cc += fix;
			map.push_back(make_pair(rr, cc));
		}
		cin >> re >> ce;
		re += fix;
		ce += fix;
		map.push_back(make_pair(re, ce));
		
		//bfs
		bfs(make_pair(rs, cs));
		cout << ans << endl;
		
		// reset
		map.clear();
		v.clear();
	}


	return 0;
}