#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int rest[42];

int main(void)
{
	int num, ans = 0;
	for (int i = 0; i < 10; ++i)
	{
		cin >> num;
		++rest[num % 42];
	}
	for (int i = 0; i < 42; ++i)
	{
		if (rest[i] > 0)	ans++;
	}
	cout << ans;
}