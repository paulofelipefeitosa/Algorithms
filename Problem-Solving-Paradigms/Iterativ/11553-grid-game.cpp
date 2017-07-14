#include <bits/stdc++.h>
using namespace std;
int n, m[10][10], cused = 0;
int backtrack(int l, int cand);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				scanf("%d", &m[i][j]);
		printf("%d\n", backtrack(0, 0));
	}
	return 0;
}
int backtrack(int l, int cand)
{
	if(l == n)
		return cand;
	int ret = 100000000;
	for(int i = 0;i < n;i++)
	{
		if(!(cused & (1<<i)))
		{
			cused |= (1<<i);
			ret = min(ret, backtrack(l+1, m[l][i] + cand));
			cused &= ~(1<<i);
		}
	}
	return ret;
}
