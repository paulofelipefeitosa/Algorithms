#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
vector<int>graph[MAX];
int n, m;
int bfs(int v);
bool isconnected();
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0;i < m;i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	int ans = -1;
	if(isconnected())
		for(int i = 1;i <= n;i++)
			ans = max(ans, bfs(i));
	printf("%d\n", ans);
	return 0;
}
bool isconnected()
{
	queue<int>fila;
	vector<bool>marc(n+2, false);
	int cont = 1;
	fila.push(1);
	marc[1] = true;
	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		for(int i = 0;i < graph[u].size();i++)
		{
			int w = graph[u][i];
			if(marc[w] == false)
			{
				marc[w] = true;
				fila.push(w);
				cont++;
			}
		}
	}
	if(cont == n)
		return true;
	else
		return false;
}
int bfs(int v)
{
	queue<int>fila;
	vector<int>marc(n+2, 0);
	int mx = 1;
	fila.push(v);
	marc[v] = 1;
	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		for(int i = 0;i < graph[u].size();i++)
		{
			int w = graph[u][i];
			if(marc[w] == 0)
			{
				marc[w] = marc[u] + 1;
				fila.push(w);
				mx = max(mx, marc[w]);
			}
		}
	}
	return mx - 1;
}
