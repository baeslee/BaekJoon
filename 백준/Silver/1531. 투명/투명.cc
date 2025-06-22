// p8320. 직사각형을 만드는 방법
// C++로 다시 풀기
#pragma warning(disable:4996)
#include<iostream>
using namespace std;

int img[101][101];

int main(void)
{
	int N, M;
	int xs, ys, xe, ye;
	int ans = 0;
	
	cin >> N >> M;
	while (N--)
	{
		cin >> xs >> ys >> xe >> ye;
		for (int x = xs; x <= xe; ++x)
		{
			for (int y = ys; y <= ye; ++y)
			{
				++img[x][y];
			}
		}
	}
	
	for (int x = 1; x <= 100; ++x)
	{
		for (int y = 1; y <= 100; ++y)
		{
			if (img[x][y] > M)	ans++;
		}
	}
	cout << ans << endl;

	return 0;
}