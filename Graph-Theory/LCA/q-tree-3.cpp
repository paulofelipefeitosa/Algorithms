#include <bits/stdc++.h>
#define MAX 10005
#define LOG 20
using namespace std;
bool mark[MAX] = {};
int n, p[MAX][LOG], dep[MAX], pai[MAX], croot[MAX];
vector<pair<int, int> >adj[MAX];
void build();
void dfs(int u, int cont, int cost);
int query1(int u, int v);
int query2(int u, int v, int k);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1;i < n;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
		pai[1] = 1;
		dfs(1, 1, 0);
		build();
		char op[10];
		while(scanf("%s", op), op[1] != 'O')
			if(op[0] == 'D')
			{
				int u, v;
				scanf("%d %d", &u, &v);
				printf("%d\n", query1(u, v));
			}
			else
			{
				int u, v, k;
				scanf("%d %d %d", &u, &v, &k);
				printf("%d\n", query2(u, v, --k));
			}
		for(int i = 1;i <= n;i++)
		{
			mark[i] = false;
			adj[i].clear();
		}
	}
	return 0;
}
void dfs(int u, int cont, int cost)
{
	mark[u] = true;
	dep[u] = cont;
	croot[u] = cost;
	for(pair<int,int>e : adj[u])
		if(!mark[e.first])
		{
			pai[e.first] = u;
			dfs(e.first, cont+1, cost+e.second);
		}
}
void build()
{
	for(int i = 1;i <= n;i++)
		for(int j = 0;1<<j < n;j++)
			p[i][j] = -1;
	for(int i = 1;i <= n;i++)
		p[i][0] = pai[i];
	for(int j = 1;1<<j < n;j++)
		for(int i = 1;i <= n;i++)
			p[i][j] = p[p[i][j-1]][j-1];
}
int query1(int u, int v)
{
	if(dep[u] < dep[v])
		swap(u, v);
	int log, uu = u, vv = v;
	for(log = 1;1<<log <= dep[u];log++);
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
	return croot[uu] + croot[vv] - (croot[pai[u]]<<1);
}
int query2(int u, int v, int k)
{
	if(k == 0)
		return u;
	bool f = false;
	if(dep[u] < dep[v])
	{
		swap(u, v);
		f = true;
	}
	int log, uu = u, vv = v;
	for(log = 1;1<<log <= dep[u];log++);
	log--;
	for(int i = log;i >= 0;i--)
		if(dep[u] - (1<<i) >= dep[v])
			u = p[u][i];
	if(u == v)
	{
		if(f)
			k = (dep[uu] - dep[vv]) - k;
		for(int i = 0;i < 15;i++)
			if(k & (1<<i))
				uu = p[uu][i];
		return uu;
	}
	else
	{
		for(int i = log;i >= 0;i--)
			if(p[u][i] != -1 && p[u][i] != p[v][i])
			{
				u = p[u][i];
				v = p[v][i];
			}
		int lca = pai[u];
		if(f)
			k = (dep[uu] + dep[vv] - (dep[lca]<<1)) - k;
		if(k <= (dep[uu] - dep[lca]))
		{
			for(int i = 0;i < 15;i++)
				if(k & (1<<i))
					uu = p[uu][i];
			return uu;
		}
		else
		{
			k = (dep[uu] + dep[vv] - (dep[lca]<<1)) - k;
			for(int i = 0;i < 15;i++)
				if(k & (1<<i))
					vv = p[vv][i];
			return vv;
		}
	}
}
