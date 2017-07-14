#include <bits/stdc++.h>
#define INF 1<<30
using namespace std;

int gelo[30], n;
int memo[1000005];
int dp(int val);

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int m;
		scanf("%d %d", &n, &m);
		for(int i = 0;i < n;i++)
			scanf("%d", &gelo[i]);
		sort(gelo, gelo+n);
		printf("%d\n", dp(m));
	}
	return 0;
}
int dp(int val)
{
	memo[0] = 0;
	for(int i = 1;i <= val;i++)
		memo[i] = INF;
	int k;
	for(int j = 0;j < n;j++)
	{
		k = gelo[j];
		for(int i = k;i <= val;i++)
			memo[i] = min(memo[i], memo[i-k] + 1);
	}
	return memo[val];
}

/*
int gelo[30], n, m;
int memo[1000005];
int dp(int val);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i = 0;i < n;i++)
			scanf("%d", &gelo[i]);
		sort(gelo, gelo+n);
		memo[0] = 0;
		for(int j = 1;j <= m;j++)
			memo[j] = INF;
		printf("%d\n", dp(m));
	}
	return 0;
}
int dp(int val)
{
	if(memo[val] != INF)
		return memo[val];
	for(int i = 0;i < n && gelo[i] <= val;i++)
		memo[val] = min(memo[val], 1 + dp(val - gelo[i]));
	return memo[val];
}*/
