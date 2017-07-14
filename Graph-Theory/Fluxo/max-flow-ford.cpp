#include <bits/stdc++.h>
using namespace std;
int n = 52, mapa[256], graph[60][60] = {}, rgraph[60][60] = {};
int fordFulkerson(int s, int t);
bool bfs(int pai[], int s, int t);
int main()
{
	for(char a = 'A', i = 1;a <= 'Z';a++, i++) mapa[a] = i;
	for(char a = 'a', i = 27;a <= 'z';a++, i++) mapa[a] = i;
	int m;
	scanf("%d", &m);
	char uu[2], vv[2];
	int f;
	for(int i = 0;i < m;i++)
	{
		scanf("%s %s %d", uu, vv, &f);
		graph[mapa[uu[0]]][mapa[vv[0]]] += f;
	}
	printf("%d\n", fordFulkerson(mapa['A'], mapa['Z']));
	return 0;
}
int fordFulkerson(int s, int t)
{
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			rgraph[i][j] = graph[i][j];
			
	int pai[60], mxflow = 0;
	while(bfs(pai, s, t))
	{
		int fpath = INT_MAX;
		for(int v = t;v != s;v = pai[v])
		{
			int u = pai[v];
			fpath = min(fpath, rgraph[u][v]);
		}
		
		for(int v = t;v != s;v = pai[v])
		{
			int u = pai[v];
			rgraph[u][v] -= fpath;
			rgraph[v][u] += fpath;
		}
		mxflow += fpath;
	}
	return mxflow;
}
bool bfs(int pai[], int s, int t)
{
	queue<int>fila;
	vector<bool>mark(60, false);
	
	fila.push(s);
	mark[s] = true;
	pai[s] = -1;
	
	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		for(int v = 1;v <= n;v++)
			if(!mark[v] && rgraph[u][v] > 0)
			{
				fila.push(v);
				pai[v] = u;
				mark[v] = true;
			}
	}
	return (mark[t] == true);
}
