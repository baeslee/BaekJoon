// p2628. 종이자르기
#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
using namespace std;

int ans;
int col[101], row[101];

int main(void)
{
	int width, height;
	cin >> width >> height;
	col[width] = 1; row[height] = 1;
	int N, id, index;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> id >> index;
		if (id == 0)
			row[index] = 1;
		else
			col[index] = 1;
	}

	int max_r = 0, max_c = 0, temp = 0;
	for (int i = 1; i <= height; ++i)
	{
		temp++;
		if (row[i] == 1)
		{
			max_r = max(max_r, temp);
			temp = 0;
		}
	}
	for (int i = 1; i <= width; ++i)
	{
		temp++;
		if (col[i] == 1)
		{
			if (temp > max_c)
				max_c = temp;
			temp = 0;
		}
	}
	ans = max_r * max_c;
	cout << ans;

	return 0;
}