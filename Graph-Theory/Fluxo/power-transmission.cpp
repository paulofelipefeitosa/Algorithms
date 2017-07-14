#include <bits/stdc++.h>
#define MAX 205
using namespace std;
int n, gp[MAX][MAX], rgp[MAX][MAX];
int timer, used[MAX], pai[MAX];
bool bfs(int s, int t);
int EKarp(int s, int t);
int main()
{
	while(~scanf("%d", &n))
	{
		memset(gp, 0, sizeof(gp));
		memset(rgp, 0, sizeof(rgp));
		for(int i = 1;i <= n;i++)
		{
			int w;
			scanf("%d", &w);
			gp[i][i+n] = w;
		}
		int m;
		scanf("%d", &m);
		while(m--)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			gp[u+n][v] += w;
		}
		int b, d;
		scanf("%d %d", &b, &d);
		while(b--)
		{
			int v;
			scanf("%d", &v);
			gp[0][v] = INT_MAX;
		}
		while(d--)
		{
			int u;
			scanf("%d", &u);
			gp[u+n][n<<1|1] = INT_MAX;
		}
		n = n<<1|1;
		printf("%d\n", EKarp(0, n));
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
		for(int v = 0;v <= n;v++)
			if(used[v] != timer && gp[u][v] > rgp[u][v])
			{
				pai[v] = u;
				used[v] = timer;
				fila.push(v);
			}
	}
	return false;
}
