#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
#define MAX 100000
int tree[4*MAX]={}, lazy[4*MAX]={}, A[MAX], n, m;
void updateRange(int pai, int L, int R, int UL, int UR, int diff);
int querySum(int pai, int L, int R, int QL, int QR);
void build(int pai, int L, int R);
int main()
{
    int q, result, l, r;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++)
        scanf("%d", &A[i]);
    build(1, 1, n);
    while(m--)
    {
        scanf("%d", &q);
        result = querySum(1, 1, n, q, q);
        printf("%d -> %d\n", result, querySum(1, 1, n, 1, n));
        if((q - result) >= 1)
            l = q - result;
        else
            l = 1;
        if((q + result) <= n)
            r = q + result;
        else
            r = n;
        updateRange(1, 1, n, l, r, -1);
    }
    printf("%d\n", querySum(1, 1, n, 1, n));
    return 0;
}
void updateRange(int pai, int L, int R, int UL, int UR, int diff)//[UL, UR] = RANGE UPDATE
{
    if(lazy[pai]!=0)//se tenho atualização pendente
    {
        tree[pai] += (R-L+1)*lazy[pai];//atualizo
        if(L!=R)//NAO SOU UMA FOLHA
        {
            lazy[left(pai)] += lazy[pai];//passo para meus filhos
            lazy[right(pai)]+= lazy[pai];
        }
        lazy[pai] = 0;
    }

    if(L > UR || R < UL || L > R) return;

    if(L >= UL && R <= UR)//estou totalmente dentro do intervalo de update
    {
        tree[pai] += (R-L+1)*diff;//Atualize o nó atual
        if(L!=R)
        {
            lazy[left(pai)] += diff;//ADIE A ATUALIZAÇÃO DOS FILHOS
            lazy[right(pai)] += diff;
        }
    }
    else
    {
        updateRange(left(pai), L, (L+R)>>1, UL, UR, diff);
        updateRange(right(pai), ((L+R)>>1)+1, R, UL, UR, diff);
        tree[pai] = tree[left(pai)] + tree[right(pai)];//O pai eh a soma de seus filhos
    }
}
int querySum(int pai, int L, int R, int QL, int QR)
{
    if(lazy[pai] != 0)//Se tem atualizações para fazer
    {
        tree[pai] += (R-L+1)*lazy[pai];
        if(L!=R)
        {
            lazy[left(pai)] += lazy[pai];
            lazy[right(pai)] += lazy[pai];
        }
        lazy[pai] = 0;
    }

    if(L > QR || R < QL || L > R) return 0;

    if(L >= QL && R <= QR) return tree[pai];

    return querySum(left(pai), L, (L+R)>>1, QL, QR) + querySum(right(pai), ((L+R)>>1)+1, R, QL, QR);
}
void build(int pai, int L, int R)
{
    if(L > R) return;

    if(L == R)
        tree[pai] = A[L];
    else
    {
        build(left(pai), L, (L+R)>>1);
        build(right(pai), ((L+R)>>1)+1, R);
        tree[pai] = tree[left(pai)] + tree[right(pai)];
    }
}
