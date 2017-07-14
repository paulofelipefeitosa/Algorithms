#include <bits/stdc++.h>
#define MAX 101
#define INF 1<<30
using namespace std;
int memo[MAX][MAX][MAX*MAX];
int a[MAX], b[MAX];
int n, k, tsoda = 0;

int dp(int i, int bts, int sumt);
bool comp(int x, int y);
int main()
{
	memset(memo, -1, sizeof(memo));
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &a[i]);
		tsoda += a[i];
	}
	int p[MAX];
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &b[i]);
		p[i] = i;
	}
	sort(p, p+n, comp);
	int sum = 0;
	while(b[p[k]] + sum < tsoda)
	{
		sum += b[p[k]];
		k++;
	}
	k++;
	printf("%d %d\n", k, tsoda - dp(0, 0, 0));
	return 0;
}
int dp(int i, int bts, int sumt)
{
	if(bts == k)
	{
		if(sumt >= tsoda)
			return 0;
		else
			return -INF;
	}
	if(i == n)
		return -INF;
	if(memo[i][bts][sumt] != -1)
		return memo[i][bts][sumt];
	return memo[i][bts][sumt] = max(dp(i+1, bts, sumt), a[i] + dp(i+1, bts+1, b[i] + sumt));
}
bool comp(int x, int y)
{
	return b[x] > b[y];
}
