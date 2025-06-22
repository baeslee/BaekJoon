// p14470. 전자레인지
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
	int A, B, C, D, E;
	int ans = 0;
	cin >> A >> B >> C >> D >> E;
	if (A < 0)
	{
		ans = abs(A) * C + D;
		A = 0;
	}
	ans += (B - A) * E;
	
	cout << ans;

	return 0;
}