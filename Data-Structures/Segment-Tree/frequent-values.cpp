#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
#define MAX 100005
using namespace std;
struct node
{
	int most, fmost, esq, fesq, dir, fdir;
};
node tree[MAX<<2];
int arr[MAX];
void build(int p, int l, int r);
void update(int i);
int query(int pai, int L, int R, int QL, int QR);
int main()
{
    int n, q;
    while(scanf("%d", &n), n)
    {
        scanf("%d", &q);
        for(int i = 1;i <= n;i++)
        	scanf("%d", &arr[i]);
        build(1, 1, n);
    }
    return 0;
}
void build(int p, int l, int r)
{
    if(l == r)
		tree[p] = (node){arr[l], 1, arr[l], 1, arr[l], 1};
    else
    {
		build(left(p), l, (l+r)>>1);
		build(right(p), ((l+r)>>1)+1, r);
		
    }
}
node merge(node nesq, node ndir)
{
	node result;
	result.esq = nesq.esq;
	result.fesq = nesq.fesq;
	result.dir = ndir.dir;
	result.fdir = ndir.fdir;
	
	result.most = ((result.fesq > result.fdir) ? result.esq : result.dir);
	result.fmost = max(result.fesq, result.fdir);
	
	if(nesq.dir == ndir.esq)
	{
		result.most = (((nesq.fdir + ndir.fesq) > result.fmost) ? nesq.dir : result.most);
		result.fmost = max((nesq.fdir + ndir.fesq), result.fmost);
	}
	else
	{
		result.most = ((nesq.fdir > result.fmost) ? nesq.dir : result.most);
		result.fmost = max()
	}
	return result;
}
int query(int pai, int L, int R, int QL, int QR)
{
    if(L > QR || R < QL) return 0;

    if(L >= QL && R <= QR) return tree[pai];

    int M = (L+R)>>1;

    return query(left(pai), L, M, QL, QR) + query(right(pai), M+1, R, QL, QR);
}
