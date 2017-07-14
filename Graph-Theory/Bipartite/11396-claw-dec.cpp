#include <bits/stdc++.h>
#define MAX 305
#define INF 1<<30
using namespace std;
vector<int>lista[MAX];
int color[MAX], v;
bool bfs_bi_check(int ori);
int main()
{
	int v1, v2;
	bool flag;
	while(scanf("%d", &v), v)
	{
		while(scanf("%d %d", &v1, &v2), (v1 || v2))
		{
			lista[v1].push_back(v2);
			lista[v2].push_back(v1);
		}
		flag = true;
		
		for(int i=1;i<=v;i++)
			color[i] = INF;
		
		for(int i=1;i<=v && flag;i++)
			if(color[i] == INF && !bfs_bi_check(i))
				flag = false;
		
		if(flag)
			puts("YES");
		else
			puts("NO");
		
		for(int i=1;i<=v;i++)
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
