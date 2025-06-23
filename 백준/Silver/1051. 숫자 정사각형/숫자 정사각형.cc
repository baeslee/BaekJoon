// p1051. 숫자 정사각형
#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int ans = 1;
int arr[51][51];
string temp;

int main(void)
{
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> temp;
		for (int j = 1; j <= M; ++j)
		{
			arr[i][j] = int(temp[j - 1]) - '0';
		}
	}

	for (int n = 2; n <= min(N,M); ++n)
	{
		for (int i = 1; i <= N - n + 1; ++i)
		{
			for (int j = 1; j <= M - n + 1; ++j) {
				if (arr[i][j] == arr[i][j + n - 1] && arr[i][j] == arr[i + n - 1][j] && arr[i][j] == arr[i + n - 1][j + n - 1])
				{
					ans = n * n;
					break;
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}