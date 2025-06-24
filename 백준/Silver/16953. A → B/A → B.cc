// p2644. 촌수계산
#include<iostream>
#include<queue>
using namespace std;

int ans, A, B;
typedef struct s
{
	long long num;
	int count;
}s;
queue <s> q;

void bfs(s n)
{
	s out, temp1, temp2;
	q.push(n);
	while (!q.empty())
	{
		out = q.front();
		q.pop();
		if (out.num == B)
		{
			ans = out.count + 1;
			return;
		}

		temp1.num = out.num * 2;
		temp1.count = out.count + 1;
		if(temp1.num <= B)
			q.push(temp1);
		temp2.num = out.num * 10 + 1;
		temp2.count = out.count + 1;
		if (temp2.num <= B)
			q.push(temp2);
	}
	ans = -1;
}

int main(void)
{
	cin >> A >> B;
	s temp = { A,0 };
	bfs(temp);
	cout << ans;
	
	return 0;
}