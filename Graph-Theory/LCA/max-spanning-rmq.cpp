#include <bits/stdc++.h>
#define MAX  20005
#define MAXE 100005
#define LOG  20
using namespace std;
int n;
int fat[MAX], peso[MAX];
int uu[MAXE], vv[MAXE], ww[MAXE];
bool mark[MAX] = {};
int p[MAX][LOG], emin[MAX][LOG], dep[MAX], ppai[MAX], pedge[MAX];
vector<pair<int, int> >adj[MAX];
void join(int u, int v);
int ffind(int x);
bool comp(int a, int b);
void build();
void dfs(int u, int cont);
int query(int u, int v);
int main()
{
	int per[MAXE];
	int m, s;
	while(~scanf("%d %d %d", &n, &m, &s))
	{
		for(int i = 1;i <= n;i++)
		{
			fat[i] = i; peso[i] = 1;
			mark[i] = false;
			adj[i].clear();
		}
		for(int i = 1;i <= m;i++)
		{
			per[i] = i;
			scanf("%d %d %d", &uu[i], &vv[i], &ww[i]);
		}
		sort(per+1, per+m+1, comp);
		for(int i = 1, cont = n-1;i <= m && cont;i++)
		{
			int u = uu[per[i]], v = vv[per[i]], w = ww[per[i]];
			if(ffind(u) != ffind(v))
			{
				join(u, v);
				adj[u].push_back(make_pair(v, w));
				adj[v].push_back(make_pair(u, w));
				cont--;
			}
		}
		dfs(1, 1);
		ppai[1] = 1; pedge[1] = 1<<30;
		build();
		while(s--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			printf("%d\n", query(u, v));
		}
	}
	return 0;
}
void dfs(int u, int cont)
{
	mark[u] = true;
	dep[u] = cont;
	for(pair<int,int>e : adj[u])
	{
		if(!mark[e.first])
		{
			ppai[e.first] = u;
			pedge[e.first] = e.second;
			dfs(e.first, cont+1);
		}
	}
}
void build()
{
	for(int i = 1;i <= n;i++)
		for(int j = 0;1 << j < n;j++)
			p[i][j] = -1;
	for(int i = 1;i <= n;i++)
		p[i][0] = ppai[i], emin[i][0] = pedge[i];
	for(int j = 1;1 << j < n;j++)
		for(int i = 1;i <= n;i++)
			if(p[i][j-1] != -1)
			{
				p[i][j] = p[p[i][j-1]][j-1];
				emin[i][j] = min(emin[i][j-1], emin[p[i][j-1]][j-1]);
			}
}
int query(int u, int v)
{
	int ans = 1<<30;
	if(dep[u] < dep[v])
		swap(u, v);
	int log;
	for(log = 1;1 << log <= dep[u];log++);
	log--;
	for(int i = log;i >= 0;i--)
		if(dep[u] - (1<<i) >= dep[v])
		{
			ans = min(ans, emin[u][i]);
			u = p[u][i];
		}
	if(u == v)
		return ans;
	for(int i = log;i >= 0;i--)
		if(p[u][i] != -1 && p[u][i] != p[v][i])
		{
			ans = min({ans, emin[u][i], emin[v][i]});
			u = p[u][i];
			v = p[v][i];
		}
	return min({ans, pedge[u], pedge[v]});
}
void join(int u, int v)
{
	u = ffind(u); v = ffind(v);
	if(u == v)
		return;
	if(peso[u] < peso[v])
	{
		fat[v] = u; peso[u] += peso[v];
	}
	else
	{
		fat[u] = v; peso[v] += peso[u];
	}
}
int ffind(int x)
{
	if(fat[x] == x)
		return x;
	else
		return fat[x] = ffind(fat[x]);
}
bool comp(int a, int b)
{
	return ww[a] > ww[b];
}
