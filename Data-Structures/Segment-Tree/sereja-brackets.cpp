#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
#define MAX 1000005
using namespace std;
struct node
{
    int open, close, mx;
};
char str[MAX];
node tree[4*MAX];
int n, m;
void build(int pai, int L, int R);
node query(int pai, int L, int R, int QL, int QR);
int main()
{
    int l, r;
    scanf("%s", str);
    n = strlen(str);
    scanf("%d", &m);
    build(1, 0, n-1);
    while(m--)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(1, 0, n-1, l-1, r-1).mx);
    }
    return 0;
}
void build(int pai, int L, int R)
{
    if(L==R)
    {
        if(str[L]=='(')
            tree[pai].open = 1, tree[pai].close = 0;
        else
            tree[pai].open = 0, tree[pai].close = 1;
        tree[pai].mx = 0;
    }
    else
    {
        build(left(pai), L, (L+R)>>1);
        build(right(pai), ((L+R)>>1)+1, R);

        int diff = min(tree[left(pai)].open, tree[right(pai)].close);

        tree[pai].mx = tree[left(pai)].mx + tree[right(pai)].mx + (diff<<1);

        tree[pai].open = tree[left(pai)].open + tree[right(pai)].open - diff;

        tree[pai].close = tree[right(pai)].close + tree[left(pai)].close - diff;
    }
}
node query(int pai, int L, int R, int QL, int QR)
{
    node result;
    result.close = result.open = result.mx = 0;
    if(L > QR || R < QL) return result;

    else if(L >= QL && R <= QR) return tree[pai];

    node esq = query(left(pai), L, (L+R)>>1, QL, QR);
    node dir = query(right(pai), ((L+R)>>1)+1, R, QL, QR);

    int diff = min(esq.open, dir.close);

    result.mx = esq.mx + dir.mx + (diff<<1);

    result.open = esq.open + dir.open - diff;

    result.close = dir.close + esq.close - diff;

    return result;
}
