#include <bits/stdc++.h>
#define MAX 105
using namespace std;
vector<int>adj[MAX];
int dgin[MAX] = {};
void BFS(int n);
int main()
{
	int n, m, v1, v2;
	while(scanf("%d %d", &n, &m), (n || m))
	{
		for(int i=0;i<m;i++)
		{
			scanf("%d %d", &v1, &v2);
			adj[v1].push_back(v2);
			dgin[v2]++;
		}
		BFS(n);
		putchar('\n');
		for(int i=1;i<=n;i++)
			adj[i].clear();
	}
	return 0;
}
void BFS(int n)
{
	queue<int>fila;
	int u, v, flag = 0;
	for(int i = 1;i <= n;i++)
		if(!dgin[i])
			fila.push(i);
	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();
		if(!flag)
		{
			printf("%d", v);
			flag = 1;
		}
		else
			printf(" %d", v);
		for(int i=0;i<adj[v].size();i++)
		{
			u = adj[v][i];
			dgin[u]--;
			if(dgin[u]==0)
				fila.push(u);
		}
	}
}
