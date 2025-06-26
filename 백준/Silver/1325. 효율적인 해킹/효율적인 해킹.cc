// 03_BFS_DFS
// p1325. 효율적인 해킹
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int mx;
int N, M;
vector <int> map[10001];
vector<bool> v(10001,false);
int ans[10001];

void bfs(int n)
{
	v.assign(10001, false);
	queue<int> q;
	q.push(n);
	v[n] = true;
	int count = 1;

	int out;
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		for(int i=0;i<map[out].size();++i)
		{
			if (v[map[out].at(i)] == false)
			{
				q.push(map[out].at(i));
				v[map[out].at(i)] = true;
				count++;
			}
		}
	}
	if (count > mx)	mx = count;
	ans[n] = count;
}
int main(void)
{
	// input
	cin >> N >> M;
	int to, from;
	for (int i = 0; i < M; ++i)
	{
		cin >> to >> from;
		map[from].push_back(to);
	}

	// bfs
	for (int i = 1; i <= N; ++i)
	{
		bfs(i);
	}

	// output
	for (int i = 1; i <= N; ++i)
	{
		if(ans[i] == mx)
			cout << i << " ";	
	}
	
	return 0;
}