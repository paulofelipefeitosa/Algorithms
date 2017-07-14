#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
#define MAX 100005
using namespace std;
vector<pair<int,int> >tree[MAX<<2];
int mx = 0, vet[MAX], pos[MAX];
void build(int p, int l, int r);
void update(int i, int val, int k);
int query(int p, int l, int r, int ql, int qr, int k);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			scanf("%d", &vet[i]);
		build(1, 1, n);
		int q, op, k = 1;
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d", &op);
			if(op == 1)//Query
			{
				int l, r, k;
				scanf("%d %d %d", &l, &r, &k);
				printf("%d\n", query(1, 1, n, l, r, k));
			}
			else
			{
				int x, w;
				scanf("%d %d", &x, &w);
				update(x, w, k++);
			}
		}
		for(int i = 1;i <= mx;i++)
			tree[i].clear();
	}
	return 0;
}
void build(int p, int l, int r)
{
	mx = max(mx, p);
	if(l == r)
	{
		tree[p].push_back(pair<int,int>(0, vet[l]));
		pos[l] = p;
	}
	else
	{
		int mid = (l+r)>>1;
		build(left(p), l, mid);
		build(right(p), mid+1, r);
		tree[p].push_back(pair<int,int>(0, tree[left(p)][0].second + tree[right(p)][0].second));
	}
}
void update(int i, int val, int k)
{
	int p = pos[i];
	int att = val - vet[i];
	vet[i] = val;
	tree[p].push_back(pair<int,int>(k, val));
	while(p>>=1)
		tree[p].push_back(pair<int,int>(k, tree[p].back().second + att));
}
int query(int p, int l, int r, int ql, int qr, int k)
{
	if(l > qr || r < ql)
		return 0;
	
	if(l >= ql && r <= qr)
	{
		int lb = lower_bound(tree[p].begin(), tree[p].end(), pair<int,int>(k, 0)) - tree[p].begin();
		
		if(lb == tree[p].size() || tree[p][lb].first > k)
			lb--;
		
		return tree[p][lb].second;
	}
	
	int mid = (l+r)>>1;
	return query(left(p), l, mid, ql, qr, k) + query(right(p), mid+1, r, ql, qr, k);
}
