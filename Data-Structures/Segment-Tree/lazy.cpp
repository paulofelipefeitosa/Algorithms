#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
#define MAX 100005
using namespace std;
char tree[4*MAX], A[MAX];
int POS[MAX], n, k;
void build(int pai, int L, int R);
void update(int i, char v);
char query(int pai, int L, int R, int QL, int QR);
int main()
{
    int num, l, r;
    char c, ans;
    while(scanf("%d %d", &n, &k)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &num);
            (num > 0) ? A[i] = 1 : (num < 0) ? A[i] = -1 : A[i] = 0;
        }
        getchar();
        build(1, 1, n);
        while(k--)
        {
            scanf("%c %d %d", &c, &l, &r); getchar();
            if(c=='P')
            {
                ans = query(1, 1, n, l, r);
                (ans > 0) ? putchar('+') : (ans < 0) ? putchar('-') : putchar('0');
            }
            else
                (r > 0) ? update(l, 1) : (r < 0) ? update(l, -1) : update(l, 0);
        }
        putchar('\n');
    }
    return 0;
}
void build(int pai, int L, int R)
{
    if(L==R)
        tree[pai] = A[L], POS[L] = pai;
    else
    {
        int M = (L+R)>>1;
        build(left(pai), L, M);
        build(right(pai), M+1, R);
        tree[pai] = tree[left(pai)] * tree[right(pai)];
    }
}
void update(int i, char v)
{
    int pai = POS[i];
    tree[pai] = v;
    while(pai>>=1)
        tree[pai] = tree[left(pai)] * tree[right(pai)];
}
char query(int pai, int L, int R, int QL, int QR)
{
    if(L > QR || R < QL) return 1;

    if(L >= QL && R <= QR) return tree[pai];

    int M = (L+R)>>1;

    return query(left(pai), L, M, QL, QR) * query(right(pai), M+1, R, QL, QR);
}
