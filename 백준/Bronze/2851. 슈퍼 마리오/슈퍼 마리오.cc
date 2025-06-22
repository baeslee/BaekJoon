// p2851. 슈퍼 마리오
#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int ans;
int main(void)
{
	int score;
	for (int i = 0; i < 10; ++i)
	{
		if (ans >= 100)	break;
		cin >> score;
		ans += score;
	}
	if (ans - 100 > 100 - (ans - score))	ans -= score;
	cout << ans;
	
	return 0;
}