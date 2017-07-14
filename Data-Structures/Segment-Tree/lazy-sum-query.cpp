#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
#define llu unsigned long long int
#define MAX 100005
using namespace std;
llu tree[4*MAX]={}, lazy[4*MAX]={};
void build(int pai, int L, int R);
void updateRange(int pai, int l, int r, int ql, int qr, llu v);
llu query(int pai, int l, int r, int ql, int qr);
int main()
{
    int t, n, k, op, p, q, v;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        build(1, 1, n);
        for(int i=0;i<k;i++)
        {
            scanf("%d", &op);
            if(!op)
            {
                scanf("%d %d %d", &p, &q, &v);
                updateRange(1, 1, n, p, q, v);
            }
            else
            {
                scanf("%d %d", &p, &q);
                printf("%llu\n", query(1, 1, n, p, q));
            }
        }
    }
    return 0;
}
void build(int pai, int L, int R)
{
    if(L==R)
        tree[pai] = lazy[pai] = 0;
    else
    {
        int M = (L+R)>>1;
        build(left(pai), L, M);
        build(right(pai), M+1, R);
        tree[pai] = lazy[pai] = 0;
    }
}
void updateRange(int pai, int l, int r, int ql, int qr, llu v)
{
    if(lazy[pai]!=0)
    {
        tree[pai] += (r-l+1)*lazy[pai];
        if(l!=r)
        {
            lazy[left(pai)] += lazy[pai];
            lazy[right(pai)] += lazy[pai];
        }
        lazy[pai] = 0;
    }

    if(l > qr || r < ql) return;

    if(l >= ql && r <= qr)
    {
        tree[pai] += (r-l+1)*v;
        if(l!=r)
        {
            lazy[left(pai)] += v;
            lazy[right(pai)] += v;
        }
    }
    else
    {
        int m = (l+r)>>1;
        updateRange(left(pai), l, m, ql, qr, v);
        updateRange(right(pai), m+1, r, ql, qr, v);
        tree[pai] = tree[left(pai)] + tree[right(pai)];
    }
}
llu query(int pai, int l, int r, int ql, int qr)
{
    if(lazy[pai]!=0)
    {
        tree[pai] += (r-l+1)*lazy[pai];
        if(l!=r)
        {
            lazy[left(pai)] += lazy[pai];
            lazy[right(pai)] += lazy[pai];
        }
        lazy[pai] = 0;
    }

    if(l > qr || r < ql) return 0;

    if(l >= ql && r <= qr) return tree[pai];

    int m = (l+r)>>1;

    return query(left(pai), l, m, ql, qr) + query(right(pai), m+1, r, ql, qr);
}
