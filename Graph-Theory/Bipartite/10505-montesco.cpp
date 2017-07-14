#include <bits/stdc++.h>
#define MAX 205
#define INF 1<<30
using namespace std;
vector<int>lista[MAX];
int color[MAX];
int bfs_bi_check(int ori);
int main()
{
	int t, ans;
	int v1, v2, v, e;
	bool flag;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &v);
		for(int i=1;i<=v;i++)
		{
			scanf("%d", &e);
			while(e--)
			{
				scanf("%d", &v1);
				lista[i].push_back(v1);
				lista[v1].push_back(i);
			}
		}
		
		for(int i=1;i<=v;i++)
			color[i] = INF;
			
		ans = 0;
		
		for(int i=1;i<=v;i++)
			if(color[i] == INF)
				ans += bfs_bi_check(i);
		
		printf("%d\n", ans);
	
		for(int i=1;i<=v;i++)
			lista[i].clear();
	}
	return 0;
}
int bfs_bi_check(int ori)
{
	queue<int>fila;
	int u, v, cont[2] = {};
	bool flag = true;
	fila.push(ori);
	color[ori] = 0;
	cont[0]++;
	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();
		for(int i=0;i<lista[v].size();i++)
		{
			u = lista[v][i];
			if(color[u] == INF)
			{
				color[u] = 1 - color[v];
				cont[color[u]]++;
				fila.push(u);
			}
			else if(color[u] == color[v])
				flag = false;
		}
	}
	if(!flag)
		return 0;
	return max(cont[0], cont[1]);
}
