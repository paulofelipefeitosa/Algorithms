#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
#define MAX 100005
using namespace std;
struct node
{
    int lazy, h, e, r, atual;
};
node tree[4*MAX];
void build(int pai, int l, int r);
void updateRange(int pai, int l, int r, int ul, int ur);
node query(int pai, int l, int r, int ql, int qr);
int main()
{
    int n, m, x, y;
    char c;
    node ans;
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        getchar();
        build(1, 1, n);
        while(m--)
        {
            scanf("%c %d %d", &c, &x, &y);
            getchar();
            if(c=='C')
            {
                ans = query(1, 1, n, x, y);
                printf("%d %d %d\n", ans.h, ans.e, ans.r);
            }
            else
                updateRange(1, 1, n, x, y);
        }
        putchar('\n');
    }
    return 0;
}
node query(int pai, int l, int r, int ql, int qr)
{
    if(tree[pai].lazy!=0)
    {
        tree[pai].atual = (tree[pai].atual + tree[pai].lazy)%3;
        if(tree[pai].atual==1)
        {
            swap(tree[pai].h, tree[pai].e);
            swap(tree[pai].h, tree[pai].r);
        }
        else if(tree[pai].atual==2)
        {
            swap(tree[pai].h, tree[pai].r);
            swap(tree[pai].h, tree[pai].e);
        }
        if(l!=r)
        {
            tree[left(pai)].lazy += tree[pai].lazy;
            tree[right(pai)].lazy += tree[pai].lazy;
        }
        tree[pai].lazy = tree[pai].atual = 0;
    }

    node result;
    result.h = result.e = result.r = 0;

    if(l > qr || r < ql) return result;

    if(l >= ql && r <= qr) return tree[pai];

    int M = (l+r)>>1;
    node esq = query(left(pai), l, M, ql, qr);
    node dir = query(right(pai), M+1, r, ql, qr);

    result.h = esq.h + dir.h;
    result.e = esq.e + dir.e;
    result.r = esq.r + dir.r;

    return result;
}
void updateRange(int pai, int l, int r, int ul, int ur)
{
    if(tree[pai].lazy!=0)
    {
        tree[pai].atual = (tree[pai].atual + tree[pai].lazy)%3;
        if(tree[pai].atual==1)
        {
            swap(tree[pai].h, tree[pai].e);
            swap(tree[pai].h, tree[pai].r);
        }
        else if(tree[pai].atual==2)
        {
            swap(tree[pai].h, tree[pai].r);
            swap(tree[pai].h, tree[pai].e);
        }
        if(l!=r)
        {
            tree[left(pai)].lazy += tree[pai].lazy;
            tree[right(pai)].lazy += tree[pai].lazy;
        }
        tree[pai].lazy = tree[pai].atual = 0;
    }

    if(l > ur || r < ul) return;

    if(l >= ul && r <= ur)//está totalmente dentro,faça a atualizacao
    {
        swap(tree[pai].h, tree[pai].e);
        swap(tree[pai].h, tree[pai].r);
        if(l!=r)
        {
            tree[left(pai)].lazy++;
            tree[right(pai)].lazy++;
        }
        tree[pai].atual = 0;
    }
    else
    {
        int M = (l+r)>>1;
        updateRange(left(pai), l, M, ul, ur);
        updateRange(right(pai), M+1, r, ul, ur);
        tree[pai].h = tree[left(pai)].h + tree[right(pai)].h;
        tree[pai].e = tree[left(pai)].e + tree[right(pai)].e;
        tree[pai].r = tree[left(pai)].r + tree[right(pai)].r;
    }
}
void build(int pai, int l, int r)
{
    tree[pai].lazy = tree[pai].atual = tree[pai].e = tree[pai].r = 0;
    if(l==r)
        tree[pai].h = 1;
    else
    {
        int M = (l+r)>>1;
        build(left(pai), l, M);
        build(right(pai), M+1, r);
        tree[pai].h = (r-l+1);
    }
}
