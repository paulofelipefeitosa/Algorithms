#include <bits/stdc++.h>
#define MAX 1005
#define LOG 12
using namespace std;
int n, father[MAX], depth[MAX], p[MAX][LOG];
bool mark[MAX] = {};
vector<int>child[MAX];
void build();
void dfs(int u, int cont);
int query(int u, int v);
int main()
{
	int t;
	scanf("%d", &t);
	for(int c = 1;c <= t;c++)
	{
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
		{
			int m;
			scanf("%d", &m);
			child[i].clear();
			while(m--)
			{
				int v;
				scanf("%d", &v);
				child[i].push_back(v);
			}
			mark[i] = false;
		}
		father[1] = 1;
		dfs(1, 1);
		build();
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", c);
		while(q--)
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
	depth[u] = cont;
	for(int i = 0;i < child[u].size();i++)
	{
		int v = child[u][i];
		if(!mark[v])
		{
			father[v] = u;
			dfs(v, cont+1);
		}
	}
}
void build()
{
	for(int i = 1;i <= n;i++)
		for(int j = 0;1 << j < n;j++)
			p[i][j] = -1;
		
	for(int i = 1;i <= n;i++)
		p[i][0] = father[i];
		
	for(int j = 1;1 << j < n;j++)
		for(int i = 1;i <= n;i++)
			if(p[i][j-1] != -1)
				p[i][j] = p[p[i][j-1]][j-1];///de i, saltar 2^(j-1), e de p[i][j-1] saltar mais 2^(j-1)
}
int query(int u, int v)
{	
	if(depth[u] < depth[v])
		swap(u, v);
		
	int log;
	for(log = 1;1 << log <= depth[u];log++);
	log--;

	for(int i =	log;i >= 0;i--)
		if(depth[u] - (1<<i) >= depth[v])
			u = p[u][i];
	
	if(u == v)
		return u;
		
	for(int i = log;i >= 0;i--)
		if(p[u][i] != -1 && p[u][i] != p[v][i])
		{
			u = p[u][i];
			v = p[v][i];
		}
	
	return father[u];
}
