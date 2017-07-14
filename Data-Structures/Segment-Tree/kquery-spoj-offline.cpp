#include <bits/stdc++.h>
#define lf(x) x<<1
#define rg(x) x<<1|1
#define MAX 30005
using namespace std;
struct QR
{
	int l, r, k;
};
QR qr[200005];
int tree[MAX<<2], pos[MAX], vet[MAX];

void build(int p, int l, int r);
void update(int i);
int query(int p, int l, int r, int ql, int qr);
bool comp1(int a, int b);
bool comp2(int a, int b);

int main()
{
	int n, p[MAX], w[200005], ans[200005];
	
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &vet[i]);
		p[i] = i;
	}
	sort(p+1, p+n+1, comp1);
	
	build(1, 1, n);
	
	int q;
	scanf("%d", &q);
	for(int i = 0;i < q;i++)
	{
		scanf("%d %d %d", &qr[i].l, &qr[i].r, &qr[i].k);
		w[i] = i;
	}
	sort(w, w+q, comp2);
	
	int po = 1;
	for(int j = 0;j < q;j++)
	{
		int x = w[j];
		while(po <= n && vet[p[po]] <= qr[x].k)
			update(p[po++]);
		ans[x] = query(1, 1, n, qr[x].l, qr[x].r);
	}
	for(int i = 0;i < q;i++)
		printf("%d\n", ans[i]);
	return 0;
}
void build(int p, int l, int r)
{
	if(l == r)
	{
		tree[p] = 1;
		pos[l] = p;
	}
	else
	{
		int mid = (l+r)>>1;
		build(lf(p), l, mid);
		build(rg(p), mid+1, r);
		tree[p] = r-l+1;
	}
}
void update(int i)
{
	int p = pos[i];
	tree[p] = 0;
	while(p>>=1)
		tree[p] = tree[lf(p)] + tree[rg(p)];
}
int query(int p, int l, int r, int ql, int qr)
{
	if(l > qr || r < ql)
		return 0;
	if(l >= ql && r <= qr)
		return tree[p];
	int mid = (l+r)>>1;
	return query(lf(p), l, mid, ql, qr) + query(rg(p), mid+1, r, ql, qr);
}
bool comp1(int a, int b)
{
	return vet[a] < vet[b];
}
bool comp2(int a, int b)
{
	return qr[a].k < qr[b].k;
}
