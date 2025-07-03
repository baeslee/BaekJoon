// 04_백트래킹
// b16938. 캠프 준비
#include<iostream>
#include<algorithm>
#include<numeric>
#include<array>
using namespace std;

int N, L, R, X;
array<int,16> lst;
array<int, 16> v;
array<int, 16> sel;
int ans;

void dfs(int n,int dep)
{
	if (n >= 2)
	{
		int mx = *max_element(sel.begin() + 1, sel.begin() + n+1);
		int mn = *min_element(sel.begin()+1, sel.begin() + n+1);
		int sum = accumulate(sel.begin()+1, sel.begin() + n+1,0);
		if (sum >= L && sum <= R && mx - mn >= X)
			ans++;
	}
	if (n == N)	return;
	
	for (int i = 1; i <= N; ++i)
	{
		if (v[i] == 0 && i > dep)
		{
			sel[n + 1] = lst[i];
			v[i] = 1;
			dfs(n + 1,i);
			v[i] = 0;
		}
	}
}

int main(void)
{
	// 입력
	cin >> N >> L >> R >> X;
	for (int i = 1; i <= N; ++i)
		cin >> lst[i];
	// 출력
	dfs(0,0);
	cout << ans;

	return 0;
}