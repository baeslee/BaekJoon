#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main(void)
{
	int N, num;
	int min = 1000001, max = -1000001;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		if (max < num)
			max = num;
		if (min > num)
			min = num;
	}
	cout << min << " " << max;

	return 0;
}