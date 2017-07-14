#include <bits/stdc++.h>
#define MAX 100005
#define LOG 20
using namespace std;
int n, ans[10];
int p[MAX][LOG], it[MAX][LOG], people[MAX][LOG][10], dep[MAX], pai[MAX];
bool mark[MAX] = {};
vector<int>adj[MAX], city[MAX];
void build();
void dfs(int u, int cont);
int query(int u, int v);
int merge(int ans[], int a[], int b[], int sa, int sb);
int mergev(int res[], int a[], vector<int>&b, int sa);
int main()
{
	int m, q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1;i < n;i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1;i <= m;i++)
	{
		int c;
		scanf("%d", &c);
		city[c].push_back(i);
	}
	pai[1] = 1;
	dfs(1, 1);
	build();
	while(q--)
	{
		int u, v, a;
		scanf("%d %d %d", &u, &v, &a);
		int k = min(query(u, v), a);
		printf("%d", k);
		for(int i = 0;i < k;i++)
			printf(" %d", ans[i]);
		putchar('\n');
	}
	return 0;
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
	{
		p[i][0] = pai[i];
		it[i][0] = city[pai[i]].size();
		for(int j = 0;j < it[i][0];j++)
			people[i][0][j] = city[pai[i]][j];
	}
	for(int j = 1;1<<j < n;j++)
		for(int i = 1;i <= n;i++)
			if(p[i][j-1] != -1)
			{
				p[i][j] = p[p[i][j-1]][j-1];
				it[i][j] = merge(people[i][j], people[i][j-1], people[p[i][j-1]][j-1], it[i][j-1], it[p[i][j-1]][j-1]);
			}
}
int query(int u, int v)
{
	int k = 0, aux[10];
	if(dep[u] < dep[v])
		swap(u, v);
		
	int log, uu = u, vv = v;
	for(log = 1;1<<log <= dep[u];log++);
	log--;
	
	for(int i = log;i >= 0;i--)
		if(dep[u] - (1<<i) >= dep[v])
		{
			k = merge(aux, ans, people[u][i], k, it[u][i]);
			for(int j = 0;j < k;j++)
				ans[j] = aux[j];
			u = p[u][i];
		}
	if(u == v)
	{
		k = mergev(aux, ans, city[uu], k);
		for(int j = 0;j < k;j++)
			ans[j] = aux[j];
		return k;
	}
		
	for(int i = log;i >= 0;i--)
		if(p[u][i] != -1 && p[u][i] != p[v][i])
		{
			k = merge(aux, ans, people[u][i], k, it[u][i]);
			for(int j = 0;j < k;j++)
				ans[j] = aux[j];
			u = p[u][i];
			
			k = merge(aux, ans, people[v][i], k, it[v][i]);
			for(int j = 0;j < k;j++)
				ans[j] = aux[j];
			v = p[v][i];
		}
	k = merge(aux, ans, people[u][0], k, it[u][0]);
	for(int j = 0;j < k;j++)
		ans[j] = aux[j];
	u = p[u][0];
	
	k = mergev(aux, ans, city[uu], k);
	for(int j = 0;j < k;j++)
		ans[j] = aux[j];
	
	k = mergev(aux, ans, city[vv], k);
	for(int j = 0;j < k;j++)
		ans[j] = aux[j];
	
	return k;
}
int merge(int res[], int a[], int b[], int sa, int sb)
{
	int sans = min(10, sa + sb);
	for(int k = 0, it1 = 0, it2 = 0;k < sans;k++)
		if(it1 == sa)
			res[k] = b[it2++];
		else if(it2 == sb)
			res[k] = a[it1++];
		else if(a[it1] < b[it2])
			res[k] = a[it1++];
		else
			res[k] = b[it2++];
	return sans;
}
int mergev(int res[], int a[], vector<int>&b, int sa)
{
	int sans = min(10, (int)(sa + b.size()));
	for(int k = 0, it1 = 0, it2 = 0;k < sans;k++)
		if(it1 == sa)
			res[k] = b[it2++];
		else if(it2 == b.size())
			res[k] = a[it1++];
		else if(a[it1] < b[it2])
			res[k] = a[it1++];
		else
			res[k] = b[it2++];
	return sans;
}
