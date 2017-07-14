#include <bits/stdc++.h>
#define lf(x) x<<1
#define rg(x) x<<1|1
#define MAX 100005
using namespace std;
pair<int,int>tree[MAX<<2];
int mx = 0, lazy[MAX<<2];
int update(int p, int l, int r, int ul, int ur, int h);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, ans = 0;
		scanf("%d", &n);
		int l, r, h;
		while(n--)
		{
			scanf("%d %d %d", &l, &r, &h);
			ans += update(1, 1, 100000, l, r-1, h);
		}
		printf("%d\n", ans);
		for(int i = 0;i <= mx;i++)
		{
			tree[i] = pair<int,int>(0, 0);
			lazy[i] = 0;
		}
		mx = 0;
	}
	return 0;
}
int update(int p, int l, int r, int ul, int ur, int h)
{
	mx = max(mx, p);
	if(lazy[p])
	{
		tree[p] = pair<int,int>(lazy[p], lazy[p]);
		if(l != r)
			lazy[lf(p)] = lazy[rg(p)] = lazy[p];
		lazy[p] = 0;
	}
	if(l > ur || r < ul)
		return 0;
	if(l >= ul && r <= ur)
	{
		//printf("(%d, %d) to (%d, %d)\n", l, r, ul, ur);
		if(h >= tree[p].second)
		{
			tree[p] = pair<int,int>(h, h);
			if(l != r)
				lazy[lf(p)] = lazy[rg(p)] = h;
			lazy[p] = 0;
			return r-l+1;
		}
		else if(h < tree[p].first)
			return 0;
	}
	int mid = (l+r)>>1;
	int ans = update(lf(p), l, mid, ul, ur, h) + update(rg(p), mid+1, r, ul, ur, h);
	tree[p].first = min(tree[lf(p)].first, tree[rg(p)].first);
	tree[p].second = max(tree[lf(p)].second, tree[rg(p)].second);
	return ans;
}
