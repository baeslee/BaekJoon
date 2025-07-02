// 04_백트래킹
// b14501. 퇴사
#include<iostream>
using namespace std;

int N;
int num[12];
int op[11];
int v[4];
int mx = -1000000000, mn = 1000000000;

void dfs(int n)
{
	if (n == N - 1)
	{
		int sum = num[1];
		for (int i = 1; i < N; ++i)
		{
			switch (op[i])
			{
			case 0:
				sum += num[i + 1];
				break;
			case 1:
				sum -= num[i + 1];
				break;
			case 2:
				sum *= num[i + 1];
				break;
			case 3:
				sum /= num[i + 1];
				break;
			}
		}
		if (sum > mx)	mx = sum;
		if (sum < mn)	mn = sum;
		
		return;
	}

	// 연산자 남아있다면 해당 연산자 삽입 dfs
	for (int i = 0; i < 4; ++i)
	{
		if (v[i] > 0)
		{
			op[n + 1] = i;
			v[i]--;
			dfs(n + 1);
			v[i]++;
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> num[i];
	for (int i = 0; i < 4; ++i)
		cin >> v[i];
	dfs(0);
	cout << mx << "\n" << mn;

	return 0;
}