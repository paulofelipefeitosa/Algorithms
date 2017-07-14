#include <bits/stdc++.h>
#define MAX 100005
#define INF 1<<30
using namespace std;
vector<int>graph[MAX];
int color[MAX];
int v1[MAX], v2[MAX];
int n, m, tot;
int bfs_bi_check(int ori);
int main()
{
	int t, x;
	scanf("%d", &t);
	for(int k = 1;k <= t;k++)
	{
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			scanf("%d", &v1[i]);
		scanf("%d", &m);
		for(int i = 1;i <= m;i++)
		{
			scanf("%d", &v2[i]);
			for(int j = 1;j <= n;j++)
			{
				if(v1[j] == 0)
				{
					if(v2[i] == 0)
					{
						graph[j].push_back(i+n);
						graph[i+n].push_back(j);
					}
				}
				else
				{
					x = v2[i]/v1[j];
					if(x*v1[j] == v2[i])
					{
						graph[j].push_back(i+n);
						graph[i+n].push_back(j);
					}
				}
			}
		}
		tot = n + m;
		for(int i = 1;i <= tot;i++)
			color[i] = INF;
		int ans = 0;
		for(int i = 1;i <= tot;i++)
			if(color[i] == INF)
				ans += bfs_bi_check(i);
		printf("Case %d: %d\n", k, ans);
		for(int i = 1;i <= tot;i++)
			graph[i].clear();
	}
	return 0;
}
int bfs_bi_check(int ori)
{
	queue<int>fila;
	int u, v, cont[2] = {};
	fila.push(ori);
	color[ori] = 0;
	cont[0]++;
	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();
		for(int i=0;i<graph[v].size();i++)
		{
			u = graph[v][i];
			if(color[u] == INF)
			{
				color[u] = 1 - color[v];
				cont[color[u]]++;
				fila.push(u);
			}
		}
	}
	return min(cont[0], cont[1]);
}

