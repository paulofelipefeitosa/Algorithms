#include <bits/stdc++.h>
#define MAX 100001
#define plli pair<long long int, int>
using namespace std;
int n;
vector<int>pai;
vector<pair<int,int> >lista[MAX];
void dijkstra();
void recur(int u);
int main()
{
    int m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
    	int u, v, ww;
        scanf("%d %d %d", &u, &v, &ww);
        lista[u].push_back(pair<int,int>(v, ww));
        lista[v].push_back(pair<int,int>(u, ww));
    }
    dijkstra();
    return 0;
}
void dijkstra()
{
    vector<long long int>cust(n+2, 1000000000000);
    pai.resize(n+2, 0);
    set<plli >fila;
    cust[1] = 0;
    fila.insert(plli(0, 1));
    while(!fila.empty())
    {
        long long int w = (*fila.begin()).first;
        int u = (*fila.begin()).second;
        fila.erase(fila.begin());
        for(int i = 0;i < lista[u].size();i++)
        {
            int v = lista[u][i].first;
            int ww = lista[u][i].second;
            if(cust[v] > (w + ww))
            {
            	fila.erase(plli(cust[v], v));
                cust[v] = w + ww;
                pai[v] = u;
                fila.insert(plli(cust[v], v));
            }
        }
    }
    if(pai[n] == 0)
        puts("-1");
    else
    {
    	recur(n);
    	putchar('\n');
    }
}
void recur(int u)
{
    if(u == 1)
    {
        printf("%d ", u);
        return;
    }
    else
    {
        recur(pai[u]);
        printf("%d ", u);
    }
}
