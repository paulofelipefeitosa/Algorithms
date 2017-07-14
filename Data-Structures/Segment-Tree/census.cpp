#include <bits/stdc++.h>
#define MAX 505
#define INF 2147483647
#define lf(x) x<<1
#define rg(x) x<<1|1
using namespace std;
int censu[MAX][MAX], pos[MAX];
pair<int,int>tree[MAX][MAX<<2];
void update(int x, int y, int v);
void build(int p, int l, int r, int idx);
pair<int,int>query(int p, int l, int r, int ql, int qr, int idx);
int main()
{
	int n;
	scanf("%d", &n);
	if(n == 0)
		return 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			scanf("%d", &censu[i][j]);
	for(int i = 1;i <= n;i++)
		build(1, 1, n, i);
	int q;
	char op[2];
	scanf("%d", &q);
	while(q--)
	{
		scanf("%s", op);
		if(op[0] == 'c')
		{
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			update(x, y, v);
		}
		else
		{
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			pair<int,int>ans = make_pair(-INF, INF), act;
			for(int i = x1;i <= x2;i++)
			{
				act = query(1, 1, n, y1, y2, i);
				ans = make_pair(max(ans.first, act.first), min(ans.second, act.second));
			}
			printf("%d %d\n", ans.first, ans.second);
		}
	}
	return 0;
}
void build(int p, int l, int r, int idx)
{
	if(l == r)
	{
		tree[idx][p] = make_pair(censu[idx][l], censu[idx][l]);
		pos[l] = p;
	}
	else
	{
		int mid = (l+r)>>1;
		build(lf(p), l, mid, idx);
		build(rg(p), mid+1, r, idx);
		tree[idx][p] = make_pair(max(tree[idx][lf(p)].first, tree[idx][rg(p)].first),
								 min(tree[idx][lf(p)].second, tree[idx][rg(p)].second));
	}
}
void update(int x, int y, int v)
{
	int p = pos[y];
	tree[x][p] = make_pair(v, v);
	while(p>>=1)
		tree[x][p] = make_pair(max(tree[x][lf(p)].first, tree[x][rg(p)].first),
							   min(tree[x][lf(p)].second, tree[x][rg(p)].second));
}
pair<int,int>query(int p, int l, int r, int ql, int qr, int idx)
{
	if(l > qr || r < ql)
		return make_pair(-INF, INF);
	if(l >= ql && r <= qr)
		return tree[idx][p];
	int mid = (l+r)>>1;
	pair<int,int>esq = query(lf(p), l, mid, ql, qr, idx);
	pair<int,int>dir = query(rg(p), mid+1, r, ql, qr, idx);
	return make_pair(max(esq.first, dir.first), min(esq.second, dir.second));
}
