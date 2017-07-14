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
#define getiii(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sc(c) putchar(c)

#define lli long long int
#define ulli unsigned long long int
#define INFi 1<<30
#define INFli 100100100100100100

#define CLS(x, a) memset(x, a, sizeof x)
#define IOS ios_base::sync_with_stdio(0)
#define debug printf("here\n")

using namespace std;

struct node
{
	int rest[3];
};

node tree[MAX<<2];
int lazy[MAX<<2];
int n, q;

void updateRange(int pai, int l, int r, int ul, int ur);
node query(int pai, int l, int r, int ql, int qr);
void build(int pai, int l, int r);

int main()
{
	int op, a, b;
	getii(n, q);
	
	build(1, 1, n);
	
	while(q--)
	{
		getiii(op, a, b);
		if(op)
			printf("%d\n", query(1, 1, n, a+1, b+1).rest[0]);
		else
			updateRange(1, 1, n, a+1, b+1);
	}
	
	return 0;
}
void updateRange(int pai, int l, int r, int ul, int ur)
{
	if(lazy[pai])
	{
		if(l != r)
		{
			lazy[left(pai)] += lazy[pai];
			lazy[right(pai)] += lazy[pai];
		}
		lazy[pai] %= 3;
		if(lazy[pai] == 1)
		{
			swap(tree[pai].rest[0], tree[pai].rest[1]);
			swap(tree[pai].rest[0], tree[pai].rest[2]);
		}
		else if(lazy[pai] == 2)
		{
			swap(tree[pai].rest[0], tree[pai].rest[2]);
			swap(tree[pai].rest[0], tree[pai].rest[1]);
		}
		lazy[pai] = 0;
	}
	
	if(l > ur || r < ul)
		return;
	
	if(l >= ul && r <= ur)
	{
		swap(tree[pai].rest[0], tree[pai].rest[1]);
		swap(tree[pai].rest[0], tree[pai].rest[2]);
		if(l != r)
		{
			lazy[left(pai)]++;
			lazy[right(pai)]++;
		}
	}
	else
	{
		updateRange(left(pai), l, (l+r)>>1, ul, ur);
		updateRange(right(pai), ((l+r)>>1)+1, r, ul, ur);
		rep(i, 0, 3)
			tree[pai].rest[i] = tree[left(pai)].rest[i] + tree[right(pai)].rest[i];
	}
}
node query(int pai, int l, int r, int ql, int qr)
{
	if(lazy[pai])
	{
		if(l != r)
		{
			lazy[left(pai)] += lazy[pai];
			lazy[right(pai)] += lazy[pai];
		}
		lazy[pai] %= 3;
		if(lazy[pai] == 1)
		{
			swap(tree[pai].rest[0], tree[pai].rest[1]);
			swap(tree[pai].rest[0], tree[pai].rest[2]);
		}
		else if(lazy[pai] == 2)
		{
			swap(tree[pai].rest[0], tree[pai].rest[2]);
			swap(tree[pai].rest[0], tree[pai].rest[1]);
		}
		lazy[pai] = 0;
	}
	
	node result;
	rep(i, 0, 3)
		result.rest[i] = 0;
	
	if(l > qr || r < ql)
		return result;
		
	if(l >= ql && r <= qr)
		return tree[pai];
	
	node esq = query(left(pai), l, (l+r)>>1, ql, qr);
	node dir = query(right(pai), ((l+r)>>1)+1, r, ql, qr);
	
	rep(i, 0, 3)
		result.rest[i] = esq.rest[i] + dir.rest[i];
		
	return result;
}
void build(int pai, int l, int r)
{
	tree[pai].rest[0] = r-l+1;
	tree[pai].rest[1] = tree[pai].rest[2] = lazy[pai] = 0;
	if(l != r)
	{
		build(left(pai), l, (l+r)>>1);
		build(right(pai), ((l+r)>>1)+1, r);
	}
}
