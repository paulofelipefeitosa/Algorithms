#include <bits/stdc++.h>
#define MAX 10005
#define MOD 5000000
using namespace std;
vector<pair<int,int> >tree[MAX<<2];
vector<long long int>tsum[MAX<<2];
long long int dp[55][MAX];
int a[MAX];
void buildt(int p, int l, int r);
void build(int p, int l, int r, int k);
long long int query(int p, int l, int r, int ql, int qr, int aj);
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++)
		dp[1][i] = 1;
	buildt(1, 1, n);
	for(int i = 2;i <= k;i++)
	{
		build(1, 1, n, i-1);
		for(int j = n;j >= 1;j--)
		{
			long long int x = query(1, 1, n, j, n, a[j]);
			dp[i][j] = x;
			cout<<x<<" ";
		}
		cout<<endl;
	}
	long long int ans = 0;
	for(int i = 1;i <= n;i++)
		ans += dp[k][i];
	printf("%d\n", ans);
	return 0;
}
void buildt(int p, int l, int r)
{
	if(l == r)
	{
		tree[p].push_back(pair<int,int>(a[l], l));
		tsum[p].push_back(1);
	}
	else
	{
		int mid = (l+r)>>1;
		buildt(p<<1, l, mid);
		buildt(p<<1|1, mid+1, r);
		merge(tree[p<<1].begin(), tree[p<<1].end(), tree[p<<1|1].begin(), tree[p<<1|1].end(), back_inserter(tree[p]));
		for(int i = 0;i < tree[p].size();i++)
			tsum[p].push_back(1);
	}
}
void build(int p, int l, int r, int k)
{
	if(l == r)
		tsum[p][0] = dp[k][l];
	else
	{
		int mid = (l+r)>>1;
		build(p<<1, l, mid, k);
		build(p<<1|1, mid+1, r, k);
		
		tsum[p][0] = dp[k][tree[p][0].second];
		for(int i = 1;i < tree[p].size();i++)
			tsum[p][i] = dp[k][tree[p][i].second] + tsum[p][i-1];
	}
}
long long int query(int p, int l, int r, int ql, int qr, int aj)
{
	if(l > qr || r < ql)
		return 0;
	if(l >= ql && r <= qr)
	{
		if(tree[p].back().first <= aj)
			return 0;
		int ub = upper_bound(tree[p].begin(), tree[p].end(), pair<int,int>(aj, (1<<30))) - tree[p].begin();
		if(ub == 0)
			return tsum[p].back();
		else
			return tsum[p].back() - tsum[p][ub-1];
	}
	int mid = (l+r)>>1;
	return query(p<<1, l, mid, ql, qr, aj) + query(p<<1|1, mid+1, r, ql, qr, aj);
}
