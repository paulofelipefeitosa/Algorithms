#include <bits/stdc++.h>
#define MAX 205
#define INF 1<<30
using namespace std;
vector<int>lista[MAX];
int color[MAX];
bool bfs_bi_check(int ori);
int main()
{
	int v1, v2, v, e;
	bool flag;
	while(scanf("%d", &v), v)
	{
		scanf("%d", &e);
		for(int i=0;i<e;i++)
		{
			scanf("%d %d", &v1, &v2);
			lista[v1].push_back(v2);
			lista[v2].push_back(v1);
		}
		flag = true;
		
		for(int i=0;i<v;i++)
			color[i] = INF;
		
		if(bfs_bi_check(0))
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
		
		for(int i=0;i<v;i++)
			lista[i].clear();
	}
	return 0;
}
bool bfs_bi_check(int ori)
{
	queue<int>fila;
	int u, v;
	fila.push(ori);
	color[ori] = 0;
	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();
		for(int i=0;i<lista[v].size();i++)
		{
			u = lista[v][i];
			if(color[u]==INF)
			{
				color[u] = 1 - color[v];
				fila.push(u);
			}
			else if(color[u] == color[v])
				return false;
		}
	}
	return true;
}
