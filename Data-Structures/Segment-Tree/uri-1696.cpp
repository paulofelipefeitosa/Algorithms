#include <bits/stdc++.h>
#define lf(x) x<<1
#define rg(x) x<<1|1
#define MAX 20005
using namespace std;
int vet[MAX], pos[MAX], tree[MAX<<2];
void build(int p, int l, int r, char op);
void update(int i, int val);
int main()
{
	char name[][8] = {{"Sanches"}, {"Rusa"}}, op = 0;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, q;
		scanf("%d %d", &n, &q);
		int bl = 1, cont = 0;
		while(bl < n)
		{
			bl<<=1;
			cont++;
		}
		for(int i = 1;i <= n;i++)
			scanf("%d", &vet[i]);
		for(int i = n+1;i <= bl;i++)
			vet[i] = 0;
		build(1, 1, bl, cont & 1);
		int ans = tree[1];
		printf("%d %s\n", ans, name[(ans & 1)^op]);
		int a, b;
		while(q--)
		{
			scanf("%d %d", &a, &b);
			update(a, b);
			int ans = tree[1];
			printf("%d %s\n", ans, name[(ans & 1)^op]);
		}
		op = !op;
	}
	return 0;
}
void build(int p, int l, int r, char op)
{
	if(l == r)
	{
		tree[p] = vet[l];
		pos[l] = p;
	}
	else
	{
		int mid = (l+r)>>1;
		build(lf(p), l, mid, !op);
		build(rg(p), mid+1, r, !op);
		if(op)
			tree[p] = tree[lf(p)] + tree[rg(p)];
		else
			tree[p] = tree[lf(p)] - tree[rg(p)];
	}
}
void update(int i, int val)
{
	int p = pos[i];
	char op = 1;
	tree[p] = val;
	while(p>>=1)
	{
		if(op)
			tree[p] = tree[lf(p)] + tree[rg(p)];
		else
			tree[p] = tree[lf(p)] - tree[rg(p)];
		op = !op;
	}
}
