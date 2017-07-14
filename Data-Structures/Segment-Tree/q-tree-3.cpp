#include <bits/stdc++.h>
#define MAX 50005
#define lf(x) x<<1
#define rg(x) x<<1|1
using namespace std;
struct node
{
	int sumt, subesq, subdir, maxs;
};
int arr[MAX], pos[MAX];
node tree[MAX<<2];
void update(int i, int k);
void build(int p, int l, int r);
node query(int p, int l, int r, int ql, int qr);
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &arr[i]);
	build(1, 1, n);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int op, x, y;
		scanf("%d %d %d", &op, &x, &y);
		if(op == 0)
			update(x, y);
		else
		{
			node ans = query(1, 1, n, x, y);
			printf("%d\n", ans.maxs);
		}
	}
	return 0;
}
void build(int p, int l, int r)
{
	if(l == r)
	{
		tree[p].sumt = tree[p].subesq = tree[p].subdir = tree[p].maxs = arr[l];
		pos[l] = p;
	}
	else
	{
		int mid = (l+r)>>1;
		build(lf(p), l, mid);
		build(rg(p), mid+1, r);
		
		tree[p].sumt = tree[lf(p)].sumt + tree[rg(p)].sumt;
		tree[p].subesq = max({tree[lf(p)].subesq, tree[lf(p)].sumt + tree[rg(p)].subesq, tree[lf(p)].sumt});
		tree[p].subdir = max({tree[rg(p)].subdir, tree[lf(p)].subdir + tree[rg(p)].sumt, tree[rg(p)].sumt});
		tree[p].maxs = max({tree[p].sumt, tree[p].subesq, tree[p].subdir, tree[lf(p)].maxs, tree[rg(p)].maxs, tree[lf(p)].subdir + tree[rg(p)].subesq});
	}
}
void update(int i, int k)
{
	int p = pos[i];
	tree[p] = (node){k, k, k, k};
	while(p>>=1)
	{
		tree[p].sumt = tree[lf(p)].sumt + tree[rg(p)].sumt;
		tree[p].subesq = max({tree[lf(p)].subesq, tree[lf(p)].sumt + tree[rg(p)].subesq, tree[lf(p)].sumt});
		tree[p].subdir = max({tree[rg(p)].subdir, tree[lf(p)].subdir + tree[rg(p)].sumt, tree[rg(p)].sumt});
		tree[p].maxs = max({tree[p].sumt, tree[p].subesq, tree[p].subdir, tree[lf(p)].maxs, tree[rg(p)].maxs, tree[lf(p)].subdir + tree[rg(p)].subesq});
	}
}
node query(int p, int l, int r, int ql, int qr)
{
	node result = (node){INT_MIN, INT_MIN, INT_MIN, INT_MIN};
	if(l > qr || r < ql)
		return result;
	if(l >= ql && r <= qr)
		return tree[p];
	int mid = (l+r)>>1;
	node esq = query(lf(p), l, mid, ql, qr);
	node dir = query(rg(p), mid+1, r, ql, qr);
	if(dir.sumt == INT_MIN)
		return esq;
	if(esq.sumt == INT_MIN)
		return dir;
	result.sumt = esq.sumt + dir.sumt;
	result.subesq = max({esq.subesq, esq.sumt, esq.sumt + dir.subesq});
	result.subdir = max({dir.subdir, dir.sumt, esq.subdir + dir.sumt});
	result.maxs = max({result.sumt, result.subesq, result.subdir, esq.maxs, dir.maxs, esq.subdir+dir.subesq});
	return result;
}
