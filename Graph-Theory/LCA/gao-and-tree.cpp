#include <bits/stdc++.h>
#define MAXQ 200005
#define MAX  100005
#define LOG  20
using namespace std;
struct QUERY
{
	int k, llca, cc;
};
int n, dep[MAX], pai[MAX], p[MAX][LOG], ass[MAX], punique[MAX];
bool mark[MAX], mark2[MAX], qans[MAXQ];
vector<int>adj[MAX];
vector<QUERY>qq[MAX];
map<int,vector<int> >pos;
void build();
void dfs(int u, int cont);
void dfs2(int u, int cont);
int query(int u, int v);
int main()
{
	int m;
	while(~scanf("%d %d", &n, &m))
	{
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", &ass[i]);
			adj[i].clear(); qq[i].clear();
			mark[i] = mark2[i] = false; punique[i] = -1;
		}
		for(int i = 1;i < n;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1, 1); pai[1] = 1;
		build();
		for(int i = 0;i < m;i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			int lca = query(a, b);
			qq[a].push_back((QUERY){i, lca, c});
			qq[b].push_back((QUERY){i, lca, c});
			
			qans[i] = false;
		}
		dfs2(1, 1);
		for(int i = 0;i < m;i++)
			if(qans[i])
				puts("Find");
			else
				puts("NotFind");
		putchar('\n');
		pos.clear();
	}
	return 0;
}
void dfs2(int u, int cont)
{
	mark2[u] = true;
	pos[ass[u]].push_back(cont);
	punique[u] = cont;
	for(int i = 0;i < qq[u].size();i++)
	{
		int l = qq[u][i].llca, c = qq[u][i].cc, kk = qq[u][i].k;
		if(!pos[c].empty() && pos[c].back() >= punique[l])
			qans[kk] = true;
	}
	for(int v : adj[u])
		if(!mark2[v])
			dfs2(v, cont+1);
	pos[ass[u]].pop_back();
	punique[u] = -1;
}
void dfs(int u, int cont)
{
	mark[u] = true;
	dep[u] = cont;
	for(int v : adj[u])
		if(!mark[v])
		{
			pai[v] = u;
			dfs(v, cont+1);
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
			if(p[i][j-1] != -1)
				p[i][j] = p[p[i][j-1]][j-1];
}
int query(int u, int v)
{
	if(dep[u] < dep[v])
		swap(u, v);
	int log;
	for(log = 1;1<<log <= dep[u];log++);
	log--;
	for(int i = log;i >= 0;i--)
		if(dep[u] - (1<<i) >= dep[v])
			u = p[u][i];
	if(u == v)
		return u;
	for(int i = log;i >= 0;i--)
		if(p[u][i] != -1 && p[u][i] != p[v][i])
		{
			u = p[u][i]; v = p[v][i];
		}
	return pai[u];
}
