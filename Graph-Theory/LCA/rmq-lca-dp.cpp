#include <bits/stdc++.h>
#define MAX 100005
#define MAXQ 5005
#define MAXK 1005
#define LOG 20
using namespace std;
int n, k, q, p[MAX][LOG], emax[MAX][LOG], dep[MAX], pai[MAX], epai[MAX];
bool mark[MAX] = {};
vector<pair<int,int> >adj[MAX];
pair<int,int>item[MAXQ];
int memo[MAXQ][MAXK];
void build();
void dfs(int u, int cont);
pair<int,int>query(int u, int v);
int dp(int i, int c);
int main()
{
	memset(memo, -1, sizeof(memo));
	scanf("%d %d", &n, &k);
	for(int i = 1;i < n;i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	pai[1] = 1; epai[1] = 0;
	dfs(1, 1);
	build();
	scanf("%d", &q);
	for(int i = 0;i < q;i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		item[i] = query(u, v);
	}
	int ans = dp(0, k);
	if(ans == 0)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}
void dfs(int u, int cont)
{
	mark[u] = true;
	dep[u] = cont;
	for(pair<int,int>e : adj[u])
		if(!mark[e.first])
		{
			pai[e.first] = u;
			epai[e.first] = e.second;
			dfs(e.first, cont+1);
		}
}
void build()
{
	for(int i = 1;i <= n;i++)
		for(int j = 0;1 << j < n;j++)
			p[i][j] = -1;
	for(int i = 1;i <= n;i++)
		p[i][0] = pai[i], emax[i][0] = epai[i];
	for(int j = 1;1 << j < n;j++)
		for(int i = 1;i <= n;i++)
			if(p[i][j-1] != -1)
			{
				emax[i][j] = max(emax[i][j-1], emax[p[i][j-1]][j-1]);
				p[i][j] = p[p[i][j-1]][j-1];
			}
}
pair<int,int>query(int u, int v)
{
	int ans = 0;
	if(dep[u] < dep[v])
		swap(u, v);
	int log, uu = u, vv = v;
	for(log = 1;1 << log <= dep[u];log++);
	log--;
	for(int i = log;i >= 0;i--)
		if(dep[u] - (1<<i) >= dep[v])
		{
			ans = max(ans, emax[u][i]);
			u = p[u][i];
		}
	if(u == v)
		return make_pair(dep[uu] - dep[vv] + 1, ans);
	for(int i = log;i >= 0;i--)
		if(p[u][i] != -1 && p[u][i] != p[v][i])
		{
			ans = max({ans, emax[u][i], emax[v][i]});
			u = p[u][i];
			v = p[v][i];
		}
	return make_pair(dep[uu] + dep[vv] - (dep[pai[u]]<<1) + 1, max({ans, epai[u], epai[v]}));
}
int dp(int i, int c)
{
	if(i == q || c == 0)
		return 0;
	if(memo[i][c] != -1)
		return memo[i][c];
	if(c < item[i].first)
		return memo[i][c] = dp(i+1, c);
	return memo[i][c] = max(dp(i+1, c), item[i].second + dp(i+1, c - item[i].first));
}
