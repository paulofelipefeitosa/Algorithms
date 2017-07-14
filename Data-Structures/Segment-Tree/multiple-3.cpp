#include <bits/stdc++.h>
#define MAX 100005
#define lf(x) x<<1
#define rg(x) x<<1|1
using namespace std;
int tree[MAX<<2][3], lazy[MAX<<2] = {};
void build(int p, int l, int r);
void update(int p, int l, int r, int ul, int ur);
int query(int p, int l, int r, int ql, int qr);
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	build(1, 1, n);
	while(q--)
	{
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		a++; b++;
		if(op == 0)
			update(1, 1, n, a, b);
		else
			printf("%d\n", query(1, 1, n, a, b));
	}
	return 0;
}
int query(int p, int l, int r, int ql, int qr)
{
	if(lazy[p])
	{
		if(l != r)
		{
			lazy[lf(p)] += lazy[p];
			lazy[rg(p)] += lazy[p];
		}
		lazy[p] %= 3;
		for(int i = 0;i < lazy[p];i++)
		{
			swap(tree[p][0], tree[p][2]);
			swap(tree[p][0], tree[p][1]);
		}
		lazy[p] = 0;
	}
	
	if(l > qr || r < ql)
		return 0;
	if(l >= ql && r <= qr)
		return tree[p][0];
	
	int mid = (l+r)>>1;
	return query(lf(p), l, mid, ql, qr) + query(rg(p), mid+1, r, ql, qr);
}
void update(int p, int l, int r, int ul, int ur)
{
	if(lazy[p])
	{
		if(l != r)
		{
			lazy[lf(p)] += lazy[p];
			lazy[rg(p)] += lazy[p];
		}
		lazy[p] %= 3;
		for(int i = 0;i < lazy[p];i++)
		{
			swap(tree[p][0], tree[p][2]);
			swap(tree[p][0], tree[p][1]);
		}
		lazy[p] = 0;
	}
	if(l > ur || r < ul)
		return;
	if(l >= ul && r <= ur)
	{
		swap(tree[p][0], tree[p][2]);
		swap(tree[p][0], tree[p][1]);
		if(l != r)
		{
			lazy[lf(p)]++;
			lazy[rg(p)]++;
		}
	}
	else
	{
		int mid = (l+r)>>1;
		update(lf(p), l, mid, ul, ur);
		update(rg(p), mid+1, r, ul, ur);
		tree[p][0] = tree[lf(p)][0] + tree[rg(p)][0];
		tree[p][1] = tree[lf(p)][1] + tree[rg(p)][1];
		tree[p][2] = tree[lf(p)][2] + tree[rg(p)][2];
	}
}
void build(int p, int l, int r)
{
	if(l == r)
		tree[p][0] = r - l + 1;
	else
	{
		int mid = (l+r)>>1;
		build(lf(p), l, mid);
		build(rg(p), mid+1, r);
		tree[p][0] = r - l + 1;
	}
}
