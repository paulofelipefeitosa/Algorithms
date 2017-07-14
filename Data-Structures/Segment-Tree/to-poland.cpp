#include <bits/stdc++.h>
#define MAX 100005
#define lf(x) x<<1
#define rg(x) x<<1|1
using namespace std;
int arr[MAX], tree[MAX<<2], pos[MAX];
void update(int i, int k);
void build(int p, int l, int r);
int query(int p, int l, int r, int ql, int qr);
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0;i < t;i++)
	{
		printf("Testcase %d:\n", i);
		int n, m;
		scanf("%d %d", &n, &m);
		for(int j = 1;j <= n;j++)
			scanf("%d", &arr[j]);
		build(1, 1, n);
		int q;
		char op[2];
		scanf("%d", &q);
		while(q--)
		{
			scanf("%s", op);
			if(op[0] == 'A')
			{
				int k;
				scanf("%d", &k);
				m += k;
			}
			else if(op[0] == 'B')
			{
				int j, k;
				scanf("%d %d", &j, &k);
				j++;
				update(j, k);
			}
			else
			{
				int i, j;
				scanf("%d %d", &i, &j);
				i++; j++;
				printf("%d\n", abs(m - query(1, 1, n, i, j)));
			}
		}
		putchar('\n');
	}
	return 0;
}
void build(int p, int l, int r)
{
	if(l == r)
	{
		tree[p] = arr[l];
		pos[l] = p;
	}
	else
	{
		int mid = (l+r)>>1;
		build(lf(p), l, mid);
		build(rg(p), mid+1, r);
		tree[p] = max(tree[lf(p)], tree[rg(p)]);
	}
}
void update(int i, int k)
{
	int p = pos[i];
	tree[p] = k;
	while(p>>=1)
		tree[p] = max(tree[lf(p)], tree[rg(p)]);
}
int query(int p, int l, int r, int ql, int qr)
{
	if(l > qr || r < ql)
		return -1;
	if(l >= ql && r <= qr)
		return tree[p];
	int mid = (l+r)>>1;
	return max(query(lf(p), l, mid, ql, qr), query(rg(p), mid+1, r, ql, qr));
}
