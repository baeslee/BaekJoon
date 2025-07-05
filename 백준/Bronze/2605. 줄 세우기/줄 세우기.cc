#include<iostream>
#include<queue>
using namespace std;

int N, temp;
int map[101];
int cost[101];

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		map[i] = i;
		cin >> cost[i];
	}
	for (int i = 2; i <= N; ++i)
	{
		for (int j = i; j > i-cost[i]; --j)
		{
			temp = map[j];
			map[j] = map[j - 1];
			map[j - 1] = temp;
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << map[i] << " ";

	return 0;
}