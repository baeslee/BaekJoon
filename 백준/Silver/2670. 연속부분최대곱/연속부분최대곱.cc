// p2670. 연속부분최대곱
// C++로 다시 풀기
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
	int N;
	double sum, max = 0;
	cin >> N;
	vector <double> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	for (int i = 0; i < N; ++i)
	{
		sum = 1;
		for (int j = i; j < N; ++j)
		{
			sum *= v[j];
			if (sum > max)	max = sum;
		}
	}
	cout << fixed;
	cout.precision(3);
	cout << max;

	return 0;
}