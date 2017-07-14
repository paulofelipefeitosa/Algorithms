#include <bits/stdc++.h>
#define MAX 100005
#define left(x) x<<1
#define right(x) x<<1|1
using namespace std;
struct node
{
    int fmax, esqmax, nesq, dirmax, ndir;
};
node tree[4*MAX];
int A[MAX], n, m;
void build(int pai, int L, int R);
node query(int pai, int L, int R, int i, int j);
int main()
{
    int x, y;
    while(scanf("%d", &n) && n)
    {
        scanf("%d", &m);
        for(int i=1;i<=n;i++)
        scanf("%d", &A[i]);
        build(1, 1, n);
        while(m--)
        {
            scanf("%d %d", &x, &y);
            printf("%d\n", query(1, 1, n, x, y).fmax);
        }
    }
    return 0;
}
void build(int pai, int L, int R)
{
    if(L==R)
        tree[pai].fmax = tree[pai].esqmax = tree[pai].dirmax = 1, tree[pai].nesq = tree[pai].ndir = A[L];
    else
    {
        build(left(pai), L, (L+R)>>1);
        build(right(pai), ((L+R)>>1)+1, R);
        tree[pai].nesq = A[L]; tree[pai].ndir = A[R];

        tree[pai].esqmax = tree[left(pai)].esqmax;
        if(tree[left(pai)].nesq == tree[right(pai)].nesq)
            tree[pai].esqmax += tree[right(pai)].esqmax;

        tree[pai].dirmax = tree[right(pai)].dirmax;
        if(tree[right(pai)].ndir == tree[left(pai)].ndir)
            tree[pai].dirmax += tree[left(pai)].dirmax;

        tree[pai].fmax = max({tree[left(pai)].fmax, tree[right(pai)].fmax, tree[pai].esqmax, tree[pai].dirmax});
        if(tree[left(pai)].ndir == tree[right(pai)].nesq)
            tree[pai].fmax = max(tree[pai].fmax, tree[left(pai)].dirmax + tree[right(pai)].esqmax);
    }
}
node query(int pai, int L, int R, int i, int j)
{
    node result;
    result.dirmax = result.esqmax = result.fmax = result.ndir = result.nesq = INT_MIN;
    if(L > j || R < i) return result;
    if(L >= i && R <= j) return tree[pai];

    node esq = query(left(pai), L, (L+R)>>1, i, j);
    node dir = query(right(pai), ((L+R)>>1)+1, R, i, j);
    result.nesq = A[L]; result.ndir = A[R];

    result.esqmax = esq.esqmax;
    if(esq.nesq == dir.nesq)
        result.esqmax += dir.esqmax;

    result.dirmax = dir.dirmax;
    if(dir.ndir == esq.ndir)
        result.dirmax += esq.dirmax;

    result.fmax = max({esq.fmax, dir.fmax, result.esqmax, result.dirmax});
    if(esq.ndir == dir.nesq)
        result.fmax = max(result.fmax, esq.dirmax + dir.esqmax);

    return result;
}
