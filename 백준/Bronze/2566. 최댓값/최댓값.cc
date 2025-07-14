#include<iostream>

using namespace std;

int map[10][10];
int mx = -1;
int main(void)
{
	int r, c;
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] > mx)
			{
				mx = map[i][j];
				r = i, c = j;
			}
		}
	}
	cout << map[r][c] << endl;
	cout << r << " " << c;
	return 0;
}
//main 리턴 void 안되나?