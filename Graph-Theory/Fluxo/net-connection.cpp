#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int n, gp[MAX][MAX], rgp[MAX][MAX];
int FordF(int s, int t);
bool bfs(int pai[], int s, int t);
int main()
{
	int cont = 1;
	while(scanf("%d", &n), n)
	{
		int s, t, c;
		scanf("%d %d %d", &s, &t, &c);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				gp[i][j] = 0;
		for(int i = 0;i < c;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			gp[u][v] += w;
			gp[v][u] += w;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", cont++, FordF(s, t));
	}
	return 0;
}
int FordF(int s, int t)
{
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			rgp[i][j] = gp[i][j];
	int pai[n+1], mxflow = 0;
	while(bfs(pai, s, t))
	{
		int fpath = INT_MAX;
		for(int v = t;v != s;v = pai[v])
		{
			int u = pai[v];
			fpath = min(fpath, rgp[u][v]);
		}
		for(int v = t;v != s;v = pai[v])
		{
			int u = pai[v];
			rgp[u][v] -= fpath;
			rgp[v][u] += fpath;
		}
		mxflow += fpath;
	}
	return mxflow;
}
bool bfs(int pai[], int s, int t)
{
	queue<int>fila;
	vector<bool>mark(n+1, false);
	fila.push(s); mark[s] = true; pai[s] = -1;
	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		for(int v = 1;v <= n;v++)
			if(!mark[v] && rgp[u][v] > 0)
			{
				fila.push(v);
				mark[v] = true;
				pai[v] = u;
			}
	}
	return (mark[t] == true);
}
