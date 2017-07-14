#include <bits/stdc++.h>
#define MAX 100005
#define left(x) x<<1
#define right(x) x<<1|1
using namespace std;
int tree[MAX<<2], arr[MAX];
void build(int p, int l, int r);
int query(int p, int l, int r, int ql, int qr);
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1;i <= t;i++)
	{
		int n, q;
		scanf("%d %d", &n, &q);
		for(int j = 1;j <= n;j++)
			scanf("%d", &arr[j]);
		build(1, 1, n);
		printf("Scenario #%d:\n", i);
		while(q--)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", query(1, 1, n, l, r));
		}
	}
	return 0;
}
void build(int p, int l, int r)
{
	if(l == r)
		tree[p] = arr[l];
	else
	{
		build(left(p), l, (l+r)>>1);
		build(right(p), ((l+r)>>1) + 1, r);
		tree[p] = min(tree[left(p)], tree[right(p)]);
	}
}
int query(int p, int l, int r, int ql, int qr)
{
	if(l > qr || r < ql || l > r)
		return INT_MAX;
	if(l >= ql && r <= qr)
		return tree[p];
	return min(query(left(p), l, (l+r)>>1, ql, qr), query(right(p), ((l+r)>>1) + 1, r, ql, qr));
}
