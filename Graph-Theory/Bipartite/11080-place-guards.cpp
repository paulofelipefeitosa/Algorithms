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
		scanf("%d %d", &v, &e);
		for(int i=0;i<e;i++)
		{
			scanf("%d %d", &v1, &v2);
			lista[v1].push_back(v2);
			lista[v2].push_back(v1);
		}
		
		for(int i=0;i<v;i++)
			color[i] = INF;
			
		ans = 0;
		flag = true;
		
		for(int i=0;i < v && flag;i++)
		{
			if(color[i] == INF)
			{
				int ret = bfs_bi_check(i);
				if(ret == -1)
					flag = false;
				else
					ans += ret;
			}
		}
		
		if(flag)
			printf("%d\n", ans);
		else
			puts("-1");
	
		for(int i=0;i<v;i++)
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
		return -1;
	if(cont[1] == 0)
		return cont[0];
	return min(cont[0], cont[1]);
}
