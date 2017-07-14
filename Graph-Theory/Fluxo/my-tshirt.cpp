#include <bits/stdc++.h>
#define MAX 55
using namespace std;
int n, gp[MAX][MAX], rgp[MAX][MAX];
int timer, used[MAX], pai[MAX];
bool bfs(int s, int t);
int EKarp(int s, int t);
int main()
{
	int t;
	map<string, int>idTshirt;
	
	idTshirt["XXL"] = 2; idTshirt["XL"] = 3; idTshirt["L"] = 4; idTshirt["M"] = 5; idTshirt["S"] = 6; idTshirt["XS"] = 7;
	
	scanf("%d", &t);
	while(t--)
	{
		memset(gp, 0, sizeof(gp));
		memset(rgp, 0, sizeof(rgp));
		
		int nTshirt, m;
		scanf("%d %d", &nTshirt, &m);
		n = m + 8;
		
		for(int u = 2;u <= 7;u++)
			gp[1][u] = nTshirt/6;
			
		for(int u = 8;u <= (m+7);u++)
			gp[u][n] = 1;
		
		string aa, bb;
		for(int u = 8;u <= (m+7);u++)
		{
			cin>>aa>>bb;
			gp[idTshirt[aa]][u] = 1;
			gp[idTshirt[bb]][u] = 1;
		}
		
		if(EKarp(1, n) == m)
			puts("YES");
		else
			puts("NO");
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
