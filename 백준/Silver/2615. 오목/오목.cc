// p2615. 오목
#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int ans;
int map[21][21];

void print(int row, int col)
{
	cout << map[row][col] << endl;
	cout << row << " " << col;
}
int main(void)
{
	for (int i = 1; i <= 19; ++i)
	{
		for (int j = 1; j <= 19; ++j)
		{
			cin >> map[i][j];
		}
	}
	
	for (int i = 1; i <= 19; ++i)
	{
		for (int j = 1; j <= 19; ++j)
		{
			// 4-1. 가로
			if (j <= 19 - 4)
			{
				if (map[i][j - 1] != 1 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1 && map[i][j + 3] == 1 && map[i][j + 4] == 1 && map[i][j + 5] != 1)
				{
					print(i, j);
					return 0;
				}
				if (map[i][j - 1] != 2 && map[i][j] == 2 && map[i][j + 1] == 2 && map[i][j + 2] == 2 && map[i][j + 3] == 2 && map[i][j + 4] == 2 && map[i][j + 5] != 2)
				{
					print(i, j);
					return 0;
				}
			}
			// 4-2. 세로
			if (i <= 19 - 4)
			{
				if (map[i - 1][j] != 1 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 1 && map[i + 3][j] == 1 && map[i + 4][j] == 1 && map[i + 5][j] != 1)
				{
					print(i, j);
					return 0;
				}
				if (map[i - 1][j] != 2 && map[i][j] == 2 && map[i + 1][j] == 2 && map[i + 2][j] == 2 && map[i + 3][j] == 2 && map[i + 4][j] == 2 && map[i + 5][j] != 2)
				{
					print(i, j);
					return 0;
				}
			}
			// 4-3. 윗대각
			if (i >= 5 && j <= 19-4)
			{
				if (map[i + 1][j - 1] != 1 && map[i][j] == 1 && map[i - 1][j + 1] == 1 && map[i - 2][j + 2] == 1 && map[i - 3][j + 3] == 1 && map[i - 4][j + 4] == 1 && map[i - 5][j + 5] != 1)
				{
					print(i, j);
					return 0;
				}
				if (map[i + 1][j - 1] != 2 && map[i][j] == 2 && map[i - 1][j + 1] == 2 && map[i - 2][j + 2] == 2 && map[i - 3][j + 3] == 2 && map[i - 4][j + 4] == 2 && map[i - 5][j + 5] != 2)
				{
					print(i, j);
					return 0;
				}
			}
			// 4-4. 아랫대각
			if (i <= 19 - 4 && j <= 19 - 4)
			{
				if (map[i - 1][j - 1] != 1 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 1 && map[i + 4][j + 4] == 1 && map[i + 5][j + 5] != 1)
				{
					print(i, j);
					return 0;
				}
				if (map[i - 1][j - 1] != 2 && map[i][j] == 2 && map[i + 1][j + 1] == 2 && map[i + 2][j + 2] == 2 && map[i + 3][j + 3] == 2 && map[i + 4][j + 4] == 2 && map[i + 5][j + 5] != 2)
				{
					print(i, j);
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}