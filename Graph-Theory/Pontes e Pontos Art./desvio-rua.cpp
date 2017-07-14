#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
vector<int>lista[MAX], graph[MAX];
int pai[MAX], peso[MAX], cc;
int tempo, numSCC;
int dfs_desc[MAX] = {}, dfs_low[MAX] = {}, visited[MAX] = {}, myscc[MAX] = {};
int cont, numBridge, desc[MAX] = {}, low[MAX] = {}, parent[MAX];
vector<int>pilha;
map<pair<int,int>, int>mapa;
void tarjan(int u);
void bridge(int u);
void join(int v1, int v2);
int ffind(int x);
void clear(int n);
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		int v1, v2, t;
		for(int i = 1;i <= n;i++)
		{
			pai[i] = i; peso[i] = 1;
		}
		cc = n;
		scanf("%d %d %d", &v1, &v2, &t);
		while(--m)
		{
			scanf("%d %d %d", &v1, &v2, &t);
			join(v1, v2);
			if(t == 1)
				lista[v1].push_back(v2);
			else
			{
				lista[v1].push_back(v2);
				lista[v2].push_back(v1);
			}
		}
		
		tempo = 1;
		numSCC = 0;
		
		if(cc > 1)//impossivel realizar mudanças
		{
			puts("*");
			clear(n);
			continue;
		}
		
		for(int i = 1;i <= n;i++)
			if(dfs_desc[i] == 0)
				tarjan(i);
		
		if(numSCC == 1)//o grafo inteiro já é fortemente conexo
		{
			puts("-");
			clear(n);
			continue;
		}
		
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j < lista[i].size();j++)
			{
				int v = lista[i][j];
				if(myscc[i] != myscc[v])
				{
					mapa[pair<int,int>(myscc[i], myscc[v])]++;
					graph[myscc[i]].push_back(myscc[v]);
					graph[myscc[v]].push_back(myscc[i]);
				}
			}
		}
		
		cont = 1;
		numBridge = 0;
		for(int i = 1;i <= numSCC;i++)
			if(desc[i] == 0)
				bridge(i);
		
		if(numBridge > 0)
			puts("2");
		else
			puts("1");
		
		clear(n);
	}
	return 0;
}
void tarjan(int u)
{
	dfs_desc[u] = dfs_low[u] = tempo++;
	pilha.push_back(u);
	visited[u] = 1;
	for(int i = 0;i < (int)lista[u].size();i++)
	{
		int v = lista[u][i];
		if(dfs_desc[v] == 0)
			tarjan(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_desc[u])
	{
		numSCC++;
		int v;
		do
		{
			v = pilha.back();
			pilha.pop_back();
			visited[v] = 0;
			myscc[v] = numSCC;
		}while(u != v);
	}
}
void bridge(int u)
{
	desc[u] = low[u] = cont++;
	for(int i = 0;i < (int)graph[u].size();i++)
	{
		int v = graph[u][i];
		if(desc[v] == 0)
		{
			parent[v] = u;
			bridge(v);
			if(low[v] > desc[u])
			{
				if((mapa[pair<int,int>(u, v)] == 1 && mapa[pair<int,int>(v, u)] == 0)
				|| (mapa[pair<int,int>(u, v)] == 0 && mapa[pair<int,int>(v, u)] == 1))
					numBridge++;
			}
			low[u] = min(low[u], low[v]);
		}
		else if(v != parent[u])
			low[u] = min(low[u], desc[v]);
	}
}
void join(int v1, int v2)
{
	v1 = ffind(v1); v2 = ffind(v2);
	if(v1 == v2)
		return;
	if(peso[v1] >= peso[v2])
	{
		pai[v2] = v1;
		peso[v1] += peso[v2];
		peso[v2] = 0;
	}
	else
	{
		pai[v1] = v2;
		peso[v2] += peso[v1];
		peso[v1] = 0;
	}
	cc--;
}
int ffind(int x)
{
	if(pai[x] == x)
		return x;
	else
		return pai[x] = ffind(pai[x]);
}
void clear(int n)
{
	for(int i = 1;i <= n;i++)
	{
		lista[i].clear();
		dfs_desc[i] = dfs_low[i] = visited[i] = 0;
	}
	for(int i = 1;i <= numSCC;i++)
	{
		graph[i].clear();
		desc[i] = low[i] = 0;
	}
	mapa.clear();
}
