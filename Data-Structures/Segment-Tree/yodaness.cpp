#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
#define MAX 30005
using namespace std;
int tree[4*MAX], POS[MAX];
void build(int pai, int L, int R);
void update(int i);
int query(int pai, int L, int R, int QL, int QR);
int main()
{
    map<string, int>mapa;
    string s;
    int t, n, result = 0, pos;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        build(1, 1, n);
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            mapa[s] = i;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            pos = mapa[s];
            result += query(1, 1, n, pos, n);
            update(pos);
        }
        printf("%d\n", result);
        mapa.clear(); result = 0;
    }
    return 0;
}
void build(int pai, int L, int R)
{
    if(L==R)
        tree[pai] = 0, POS[L] = pai;
    else
    {
        build(left(pai), L, (L+R)>>1);
        build(right(pai), ((L+R)>>1)+1, R);
        tree[pai] = 0;
    }
}
void update(int i)
{
    for(int node = POS[i];node > 0;node >>= 1)
        tree[node]++;
}
int query(int pai, int L, int R, int QL, int QR)
{
    if(L > QR || R < QL) return 0;

    if(L >= QL && R <= QR) return tree[pai];

    int M = (L+R)>>1;

    return query(left(pai), L, M, QL, QR) + query(right(pai), M+1, R, QL, QR);
}
