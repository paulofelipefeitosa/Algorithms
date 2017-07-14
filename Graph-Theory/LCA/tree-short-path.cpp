#include <bits/stdc++.h>
#define MAX 100005
#define LOG 20
#define ll long long int
using namespace std;
int pai[MAX], dep[MAX], n, p[MAX][LOG];
ll croot[MAX];
bool mark[MAX] = {};
vector<pair<int,int> >adj[MAX];
void build();
void dfs(int u, int cont, ll cost);
ll query(int u, int v);
int main()
{
	while(scanf("%d", &n), n)
	{
		for(int i = 1;i < n;i++)
		{
			int u, w;
			scanf("%d %d", &u, &w);
			adj[u].push_back(make_pair(i, w));
			adj[i].push_back(make_pair(u, w));
		}
		dfs(0, 1, 0);
		pai[0] = 0;
		build();
		int q;
		scanf("%d", &q);
		while(q--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			if(q)
				printf("%lld ", query(u, v));
			else
				printf("%lld\n", query(u, v));
		}
		for(int i = 0;i < n;i++)
		{
			adj[i].clear();
			mark[i] = false;
		}
	}
	return 0;
}
void dfs(int u, int cont, ll cost)
{
	mark[u] = true;
	dep[u] = cont;
	croot[u] = cost;
	for(int i = 0;i < adj[u].size();i++)
	{
		int v = adj[u][i].first, w = adj[u][i].second;
		if(!mark[v])
		{
			pai[v] = u;
			dfs(v, cont+1, cost+w);
		}
	}
}
void build()
{
	for(int i = 0;i < n;i++)
		for(int j = 0;1 << j < n;j++)
			p[i][j] = -1;
			
	for(int i = 0;i < n;i++)
		p[i][0] = pai[i];
		
	for(int j = 1;1 << j < n;j++)
		for(int i = 0;i < n;i++)
			if(p[i][j-1] != -1)
				p[i][j] = p[p[i][j-1]][j-1];
}
ll query(int u, int v)
{
	if(u == v)
		return 0;
	
	if(dep[u] < dep[v])
		swap(u, v);
	
	int uu = u, vv = v;
		
	int log;
	for(log = 1;1 << log <= dep[u];log++);
	log--;
	
	for(int i = log;i >= 0;i--)
		if(dep[u] - (1<<i) >= dep[v])
			u = p[u][i];
			
	if(u == v)
		return croot[uu] - croot[vv];
	
	for(int i = log;i >= 0;i--)
		if(p[u][i] != -1 && p[u][i] != p[v][i])
		{
			u = p[u][i];
			v = p[v][i];
		}
	int l = pai[u];
	return croot[uu] + croot[vv] - (croot[l]<<1);
}
