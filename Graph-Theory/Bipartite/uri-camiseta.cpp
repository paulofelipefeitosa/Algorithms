#include <bits/stdc++.h>
#define MAX 105
#define INF 1<<30
using namespace std;
vector<int>graph[MAX];
int color[MAX];
int n, m, qnt;
char str[5];
bool bfs_bi_check(int ori);
void dooo(int u);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		qnt = n/6;
		for(int i = 1;i <= m;i++)
		{
			getchar();
			scanf("%[^ \n]s", str);
			printf("%s\n", str);
			dooo(i);
			getchar();
			scanf("%[^ \n]s", str);
			printf("%s\n", str);
			dooo(i);
		}
		int tot = m + n;
		for(int i = 1;i <= tot;i++)
			color[i] = INF;
		bool flag = true;
		for(int i = 1;i <= tot && flag;i++)
			if(color[i] == INF && !bfs_bi_check(i))
				flag = false;
		if(flag)
			puts("YES");
		else
			puts("NO");
		for(int i = 1;i <= tot;i++)
			graph[i].clear();
		puts("");
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
		u = fila.front();
		fila.pop();
		for(int i = 0;i < (int)graph[u].size();i++)
		{
			v = graph[u][i];
			if(color[v] == INF)
			{
				color[v] = 1 - color[u];
				fila.push(v);
			}
			else if(color[v] == color[u])
				return false;
		}
	}
	return true;
}
void dooo(int u)
{
	if(strcmp(str, "L") == 0)
	{
		for(int i = m + 1;i <= m + qnt;i++)
		{
			graph[u].push_back(i); graph[i].push_back(u);
		}
	}
	else if(strcmp(str, "M") == 0)
	{
		for(int i = m + qnt + 1;i <= m + (qnt<<1);i++)
		{
			graph[u].push_back(i); graph[i].push_back(u);
		}
	}
	else if(strcmp(str, "S") == 0)
	{
		for(int i = m + (qnt<<1) + 1;i <= m + (qnt*3);i++)
		{
			graph[u].push_back(i); graph[i].push_back(u);
		}
	}
	else if(strcmp(str, "XL") == 0)
	{
		for(int i = m + (qnt*3) + 1;i <= m + (qnt<<2);i++)
		{
			graph[u].push_back(i); graph[i].push_back(u);
		}
	}
	else if(strcmp(str, "XS") == 0)
	{
		for(int i = m + (qnt<<2) + 1;i <= m + (qnt*5);i++)
		{
			graph[u].push_back(i); graph[i].push_back(u);
		}
	}
	else if(strcmp(str, "XXL") == 0)
	{
		for(int i = m + (qnt*5) + 1;i <= m + (qnt*6);i++)
		{
			graph[u].push_back(i); graph[i].push_back(u);
		}
	}
}
