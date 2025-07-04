#include<iostream>
#include<queue>
using namespace std;

int N, K, ans;
int v[100001];
int step;

void bfs(int n)
{
	queue<int> q;
	q.push(n);
	v[n] = 1;
	int len;
	int out;
	while (!q.empty())
	{
		len = q.size();
		for (int i = 0; i < len; ++i)
		{
			out = q.front();
			q.pop();

			if (out == K)
				return;

			if (out - 1 >= 0 && v[out - 1]==0)
			{
				q.push(out - 1);
				v[out - 1] = 1;
			}
			if (out + 1 <= 100000 && v[out + 1] == 0)
			{
				q.push(out + 1);
				v[out + 1] = 1;
			}
			if (out *2 <= 100000 && v[out *2] == 0)
			{
				q.push(out *2);
				v[out *2] = 1;
			}
		}
		step++;
	}
}

int main(void)
{
	cin >> N >> K;
	bfs(N);
	cout << step;
	
	return 0;
}
