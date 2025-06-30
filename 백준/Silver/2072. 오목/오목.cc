// 02_2차원배열
// p2072. 오목
#include<iostream>
#include<vector>
using namespace std;

int map[21][21];

int horizontal(int row, int col)
{
	int count = 1;
	for (int i = 1;; ++i)
	{
		if (map[row][col - i] != map[row][col])
			break;
		count++;
	}
	for (int i = 1;; ++i)
	{
		if (map[row][col + i] != map[row][col])
			break;
		count++;
	}
	return count;
}

int vertical(int row, int col)
{
	int count = 1;
	for (int i = 1;; ++i)
	{
		if (map[row - i][col] != map[row][col])
			break;
		count++;
	}
	for (int i = 1;; ++i)
	{
		if (map[row + i][col] != map[row][col])
			break;
		count++;
	}
	return count;
}

int upper(int row, int col)
{
	int count = 1;
	for (int i = 1;; ++i)
	{
		if (map[row - i][col - i] != map[row][col])
			break;
		count++;
	}
	for (int i = 1;; ++i)
	{
		if (map[row + i][col + i] != map[row][col])
			break;
		count++;
	}
	return count;
}

int lower(int row, int col)
{
	int count = 1;
	for (int i = 1;; ++i)
	{
		if (map[row + i][col - i] != map[row][col])
			break;
		count++;
	}
	for (int i = 1;; ++i)
	{
		if (map[row - i][col + i] != map[row][col])
			break;
		count++;
	}
	return count;
}

int main(void)
{
	int N, r, c;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> r >> c;

		// 흑돌
		if (i % 2 == 1)
			map[r][c] = 1;
		// 백돌
		else 
			map[r][c] = 2;
		if (horizontal(r, c) == 5 || vertical(r, c) == 5 || upper(r, c) == 5 || lower(r, c) == 5)
		{
			cout << i;
			return 0;
		}
		
	}
	cout << -1;
	
	return 0;
}