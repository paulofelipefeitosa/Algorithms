#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
struct QUERY
{
	int p, k, idx;
};
int a[MAX], dp[MAX], kk[MAX], n;
int ans[MAX];
QUERY queries[MAX];
bool comp(QUERY a, QUERY b);
void build(int k, int n);
int solve(int p, int k);
int main()
{
	int lastk = 1;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	int q;
	scanf("%d", &q);
	for(int i = 0;i < q;i++)
	{
		scanf("%d %d", &queries[i].p, &queries[i].k);
		queries[i].idx = i;
	}
	int s = sqrt(q) + 1;
	sort(queries, queries + q, comp);
	for(int i = 0;i < q;i++)
	{
		if(q % s == 0)
			build(lastk, n);
		ans[queries[i].idx] = solve(queries[i].p, queries[i].k);
		lastk = queries[i].k;
	}
	for(int i = 0;i < q;i++)
		printf("%d\n", ans[i]);
	return 0;
}
int solve(int p, int k)
{
	if(p > n)
		return 0;
	else if(dp[p] == 1)
		return 1;
	else if(kk[p] == k)
		return dp[p];
	else
	{
		int steps = solve(p + a[p] + k, k);
		dp[p] = steps + 1;
		kk[p] = k;
		return dp[p];
	}
}
void build(int k, int n)
{
	for(int i = n;i >= 1;i--)
		if(i + a[i] + k <= n)
		{
			dp[i] = dp[i + a[i] + k] + 1;
			kk[i] = k;
		}
		else
		{
			dp[i] = 1;
			kk[i] = -1;
		}
}
bool comp(QUERY a, QUERY b)
{
	if(a.k == b.k)
		return a.p < b.p;
	return a.k < b.k;
}
