// p8320. 직사각형을 만드는 방법
// C++로 다시 풀기
#pragma warning(disable:4996)
#include<iostream>
using namespace std;

int main(void)
{
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			if (i * j > n)	break;
			ans++;
		}
	}
	cout << ans;

	return 0;
}