#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	int N, X;
	cin >> N >> X;
	int arr[10000];
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; ++i)
	{
		if(arr[i] < X)
			cout << arr[i] << " ";
	}
	return 0;
}

