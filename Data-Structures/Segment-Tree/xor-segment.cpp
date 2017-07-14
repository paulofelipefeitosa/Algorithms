#include <bits/stdc++.h>
#define lli long long int
#define left(x) x<<1
#define right(x) x<<1|1
#define MAX 100005
using namespace std;
int tree[20][4*MAX] = {};
int lazy[20][4*MAX] = {};
void update(int pai, int l, int r, int ul, int ur, int bit);
int query(int pai, int l, int r, int ql, int qr, int bit);
int main()
{
    int n, m, num, t, x, y, our, ans;
    lli result;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &num);
        for(int j=0;j<20;j++)
            if(num & (1<<j))
                update(1, 1, n, i, i, j);
    }
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &t);
        if(t==1)
        {
            result = 0;
            scanf("%d %d", &x, &y);
            for(int j=0;j<20;j++)
            {
                ans = query(1, 1, n, x, y, j);
                result += (1<<j)*(lli)ans;
            }
            printf("%I64d\n", result);
        }
        else
        {
            scanf("%d %d %d", &x, &y, &our);
            for(int j=0;j<20;j++)
                if(our & (1<<j))
                    update(1, 1, n, x, y, j);
        }
    }
    return 0;
}
int query(int pai, int l, int r, int ql, int qr, int bit)
{
    if(lazy[bit][pai]&1)
    {
        tree[bit][pai] = (r-l+1) - tree[bit][pai];
        if(l!=r)
        {
            lazy[bit][left(pai)] += lazy[bit][pai];
            lazy[bit][right(pai)] += lazy[bit][pai];
        }
        lazy[bit][pai] = 0;
    }
    else
        lazy[bit][pai] = 0;

    if(l > qr || r < ql) return 0;

    if(l >= ql && r <= qr) return tree[bit][pai];

    int M = (l+r)>>1;
    return query(left(pai), l, M, ql, qr, bit) + query(right(pai), M+1, r, ql, qr, bit);
}
void update(int pai, int l, int r, int ul, int ur, int bit)
{
    if(lazy[bit][pai]&1)
    {
        tree[bit][pai] = (r-l+1) - tree[bit][pai];
        if(l!=r)
        {
            lazy[bit][left(pai)] += lazy[bit][pai];
            lazy[bit][right(pai)] += lazy[bit][pai];
        }
        lazy[bit][pai] = 0;
    }
    else
        lazy[bit][pai] = 0;

    if(l > ur || r < ul) return;

    if(l >= ul && r <= ur)
    {
        tree[bit][pai] = (r-l+1) - tree[bit][pai];
        if(l!=r)
        {
            lazy[bit][left(pai)]++;
            lazy[bit][right(pai)]++;
        }
    }
    else
    {
        int M = (l+r)>>1;
        update(left(pai), l, M, ul, ur, bit);
        update(right(pai), M+1, r, ul, ur, bit);
        tree[bit][pai] = tree[bit][left(pai)] + tree[bit][right(pai)];
    }
}
