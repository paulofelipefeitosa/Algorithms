#include <bits/stdc++.h>
using namespace std;
int bar[25], n, p;
char memo[25][1005];
bool dp(int i, int val);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &p);
		for(int i = 0;i < p;i++)
		{
			scanf("%d", &bar[i]);
			for(int j = 0;j <= n;j++)
				memo[i][j] = -1;
		}
		sort(bar, bar+p);
		if(dp(0, n))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
bool dp(int i, int val)
{
	if(val == 0) 			return true;
	if(i == p)				return false;
	if(val-bar[i] < 0)		return false;
	if(memo[i][val] != -1)	return memo[i][val];
	return memo[i][val] = dp(i+1, val) || dp(i+1, val-bar[i]);
}
