#include <bits/stdc++.h>
#define MAX 40
using namespace std;
int n = 38, gp[MAX][MAX], rgp[MAX][MAX];
int timer, used[MAX], pai[MAX];
int EKarp(int s, int t);
bool bfs(int s, int t);
int main()
{
	string str;
	char ans[12];
	int s = 1, t = 38, sum = 0;
	while(getline(cin, str))
	{
		if(str.empty())
		{
			for(int i = 2;i < 12;i++)
				gp[i][t] = 1;
			if(sum == EKarp(s, t))
			{
				for(int i = 0;i < 10;i++)
					ans[i] = '_';
				for(int i = 12;i <= 37;i++)
					for(int j = 2;j <= 11;j++)
						if(rgp[i][j] == 1)
							ans[j-2] = i-12+'A';
				ans[10] = '\0';
				printf("%s\n", ans);
			}
			else
				puts("!");
			
			sum = 0;
			memset(gp, 0, sizeof(gp));
			memset(rgp, 0, sizeof(rgp));
		}
		else
		{
			char c = str[0];
			int m = str[1] - '0';
			gp[s][c-'A'+12] = m;
			sum += m;
			int tam = str.size() - 1;
			for(int i = 3;i < tam;i++)
				gp[c-'A'+12][str[i]-'0'+2] = 1;
		}
	}
	for(int i = 2;i < 12;i++)
		gp[i][t] = 1;
	if(sum == EKarp(s, t))
	{
		for(int i = 0;i < 10;i++)
			ans[i] = '_';
		for(int i = 12;i <= 37;i++)
			for(int j = 2;j <= 11;j++)
				if(rgp[i][j] == 1)
					ans[j-2] = i-12+'A';
		ans[10] = '\0';
		printf("%s\n", ans);
	}
	else
		puts("!");
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
