#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int n, gp[MAX][MAX], rgp[MAX][MAX];
int timer, used[MAX], pai[MAX];
bool bfs(int s, int t);
int EKarp(int s, int t);
int main()
{
	int m;
	while(scanf("%d %d", &n, &m), (n || m))
	{
		memset(gp, 0, sizeof(gp));
		memset(rgp, 0, sizeof(rgp));
		for(int i = 2;i < n;i++)
		{
			int u, w;
			scanf("%d %d", &u, &w);
			gp[u][u+n] = w;
		}
		gp[1][1+n] = INT_MAX;
		gp[n][n+n] = INT_MAX;
		while(m--)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			gp[u+n][v] += w;
			gp[v+n][u] += w;
		}
		n <<= 1;
		printf("%d\n", EKarp(1, n));
	}
	return 0;
}
int EKarp(int s, int t)
{
	memset(used, 0, sizeof(used));
	timer = 1;
	int mxflow = 0;
	while(bfs(s, t))
	{
		timer++;
		int fpath = INT_MAX;
		for(int v = t;v != s;v = pai[v])
		{
			int u = pai[v];
			fpath = min(fpath, gp[u][v] - rgp[u][v]);
		}
		for(int v = t;v != s;v = pai[v])
		{
			int u = pai[v];
			rgp[u][v] += fpath;
			rgp[v][u] -= fpath;
		}
		mxflow += fpath;
	}
	return mxflow;
}
bool bfs(int s, int t)
{
	queue<int>fila;
	fila.push(s);
	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		if(u == t)
			return true;
		for(int v = 1;v <= n;v++)
			if(used[v] != timer && gp[u][v] > rgp[u][v])
			{
				pai[v] = u;
				used[v] = timer;
				fila.push(v);
			}
	}
	return false;
}
