#include <bits/stdc++.h>
#define MAX 215
using namespace std;
int n, gp[MAX][MAX], rgp[MAX][MAX];
int timer, used[MAX], pai[MAX];
bool bfs(int s, int t);
int EKarp(int s, int t);
int main()
{
	int t, a[MAX], b[MAX];
	scanf("%d", &t);
	for(int l = 1;l <= t;l++)
	{
		memset(gp, 0, sizeof(gp));
		memset(rgp, 0, sizeof(rgp));
		int k1, k2;
		scanf("%d", &k1);
		for(int i = 0;i < k1;i++)
			scanf("%d", &a[i]);
		scanf("%d", &k2);
		for(int i = 0;i < k2;i++)
			scanf("%d", &b[i]);
		n = k1 + k2 + 2;
		for(int i = 2, o = 0;o < k1;i++, o++)
			for(int j = 2 + k1, p = 0;p < k2;j++, p++)
				if(a[o] == 0)
				{
					if(b[p] == 0)
						gp[i][j] = 1;
					else
						gp[i][j] = 0;
				}
				else if(b[p] % a[o] == 0)
					gp[i][j] = 1;
				else
					gp[i][j] = 0;
		for(int i = 2, o = 0;o < k1;i++, o++)
			gp[1][i] = 1;
		for(int j = 2 + k1, p = 0;p < k2;j++, p++)
			gp[j][n] = 1;
		printf("Case %d: %d\n", l, EKarp(1, n));
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
