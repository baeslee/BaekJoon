// p10431. 줄세우기
// C++로 다시 풀기
#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int ans;
int line[20];
int main(void)
{
	int P, T, temp;
	cin >> P;
	for (int t = 1; t <= P; ++t)
	{
		ans = 0;
		cin >> T;
		for (int i = 0; i < 20; ++i)
			cin >> line[i];
		
		for (int rear = 1; rear < 20; ++rear)
		{
			for (int front = 0; front < rear; ++front)
			{
				if (line[front] > line[rear])
				{
					temp = line[rear];
					for (int i = rear; i > front; --i)
					{
						line[i] = line[i - 1];
						ans++;
					}
					line[front] = temp;
					break;
				}
			}
		}
		cout << t << " " << ans << endl;
	}
	return 0;
}