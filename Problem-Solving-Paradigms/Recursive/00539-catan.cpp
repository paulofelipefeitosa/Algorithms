#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >graph[30];
int used = 0, ans = 0;
void backtrack(int u, int cont);
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m), n || m)
	{
		int v1, v2;
		for(int i = 0;i < m;i++)
		{
			scanf("%d %d", &v1, &v2);
			graph[v1].push_back(pair<int,int>(v2, i));
			graph[v2].push_back(pair<int,int>(v1, i));
		}
		used = ans = 0;
		for(int i = 0;i < n;i++)
			backtrack(i, 0);
		printf("%d\n", ans);
		for(int i = 0;i < n;i++)
			graph[i].clear();
	}
	return 0;
}
void backtrack(int u, int cont)
{
	ans = max(ans, cont);
	int v, id;
	for(int i = 0;i < (int)graph[u].size();i++)
	{
		v = graph[u][i].first;
		id = graph[u][i].second;
		if(!(used & (1<<id)))
		{
			used |= (1<<id);
			backtrack(v, cont+1);
			used &= ~(1<<id);
		}
	}
}

