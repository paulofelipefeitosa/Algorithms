#include <bits/stdc++.h>

#define MAX 100005
#define left(x) x<<1
#define right(x) x<<1|1

#define rep(i, l, r) for(int i = l;i < r;i++)
#define repi(i, l, r) for(int i = l;i <= r;i++)

#define pi pair<int,int>
#define vi vector<int>
#define pb push_back

#define fi first
#define se second

#define geti(a) scanf("%d", &a)
#define getii(a, b) scanf("%d %d", &a, &b)
#define sc(c) putchar(c)

#define lli long long int
#define ulli unsigned long long int

#define INFi 1<<30
#define INFli 100100100100100100

#define CLS(x, a) memset(x, a, sizeof x)

#define IOS ios_base::sync_with_stdio(0)

#define debug printf("here\n")

using namespace std;

pi info[MAX], ord[MAX];
int tree[MAX<<2], pos[MAX], n, N;
int ans[MAX];

void update(int i, int val);
int query(int pai, int l, int r, int ql, int qr);
void build(int pai, int l, int r);

int main()
{
	geti(n);
	repi(i, 1, n)
	{
		getii(info[i].fi, info[i].se);
		ord[i].fi = info[i].fi;
		ord[i].se = i;
	}
	sort(info+1, info+n+1);
	sort(ord+1, ord+n+1);
	
	build(1, 1, n);
	
	for(int i = n;i >= 1;i--)
	{
		int mx = lower_bound(info+i+1, info+n+1, pi(info[i].fi + info[i].se - 1, 0)) - info;//quem eu derrubo
		mx = min(mx, n);
		if(info[mx].fi > (info[i].fi + info[i].se - 1))
			mx--;
		mx = max(mx, query(1, 1, n, i+1, mx));//dos que eu derrubo, eu vou chegar no maximo aonde?
		update(i, mx);
		ans[ord[i].se] = mx - i + 1;
	}
	
	repi(i, 1, n)
		printf("%d ", ans[i]);
	sc('\n');
	
	return 0;
}
void build(int pai, int l, int r)
{
	if(l != r)
	{
		build(left(pai), l, (l+r)>>1);
		build(right(pai), ((l+r)>>1)+1, r);
		tree[pai] = 0;
	}
	else
	{
		tree[pai] = 0;
		pos[l] = pai;
	}
}
int query(int pai, int l, int r, int ql, int qr)
{
	if(l > qr || r < ql || ql > qr)
		return 0;
	if(l >= ql && r <= qr)
		return tree[pai];
	return max(query(left(pai), l, (l+r)>>1, ql, qr), query(right(pai), ((l+r)>>1)+1, r, ql, qr));
}
void update(int i, int val)
{
	int pai = pos[i];
	tree[pai] = val;
	do
	{
		pai>>=1;
		tree[pai] = max(tree[left(pai)], tree[right(pai)]);
	}
	while(pai);
}
