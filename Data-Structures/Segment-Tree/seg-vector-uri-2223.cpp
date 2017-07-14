#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
#define MAX 100005
using namespace std;
int upd[MAX], upv[MAX], mx = 0;
vector<pair<int,int> >tree[MAX<<2];
vector<int>tsum[MAX<<2];
void build(int p, int l, int r);
int query(int p, int l, int r, int ql, int qr, int ell, int elr);
int main()
{
	int t, qql[MAX], qqr[MAX], qqk[MAX], sum[MAX] = {}, vet[MAX];
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", &vet[i]);
			sum[i] = vet[i] + sum[i-1];
		}
		int q, pt = 0, k = 1, op;
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d", &op);
			if(op == 1)//Query
			{
				scanf("%d %d %d", &qql[pt], &qqr[pt], &qqk[pt]);
				pt++;
			}
			else
			{
				int x, w;
				scanf("%d %d", &x, &w);
				upd[k] = x;
				upv[k++] = w - vet[x];
				vet[x] = w;
			}
		}
		build(1, 1, k-1);
		for(int i = 0;i < pt;i++)
		{
			if(qqk[i] == 0)
				printf("%d\n", sum[qqr[i]] - sum[qql[i]-1]);
			else
				printf("%d\n", sum[qqr[i]] - sum[qql[i]-1] + query(1, 1, k-1, 1, qqk[i], qql[i], qqr[i]));
		}
		for(int i = 1;i <= mx;i++)
		{
			tree[i].clear();
			tsum[i].clear();
		}
	}
	return 0;
}
void build(int p, int l, int r)
{
	mx = max(mx, p);
	if(l == r)
	{
		tree[p].push_back(pair<int,int>(upd[l], l));
		tsum[p].push_back(upv[l]);
	}
	else
	{
		int mid = (l+r)>>1;
		build(left(p), l, mid);
		build(right(p), mid+1, r);
		merge(tree[left(p)].begin(), tree[left(p)].end(), tree[right(p)].begin(), tree[right(p)].end(), back_inserter(tree[p]));
		
		tsum[p].push_back(upv[tree[p][0].second]);
		for(int i = 1;i < tree[p].size();i++)
			tsum[p].push_back(upv[tree[p][i].second] + tsum[p].back());
	}
}
int query(int p, int l, int r, int ql, int qr, int ell, int elr)
{
	if(l > qr || r < ql)
		return 0;
	
	if(l >= ql && r <= qr)
	{
		if(tree[p][0].first > elr)
			return 0;
		int lb = lower_bound(tree[p].begin(), tree[p].end(), pair<int,int>(ell,0)) - tree[p].begin();
		int ub = upper_bound(tree[p].begin(), tree[p].end(), pair<int,int>(elr,(1<<30))) - tree[p].begin();
		
		if(tree[p].size() == ub || tree[p][ub].first > elr)
			ub--;
		return tsum[p][ub] - ((lb == 0) ? 0 : tsum[p][lb-1]);
	}
	int mid = (l+r)>>1;
	return query(left(p), l, mid, ql, qr, ell, elr) + query(right(p), mid+1, r, ql, qr, ell, elr);
}
