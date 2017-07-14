#include <bits/stdc++.h>
#define geti(a) scanf("%d", &a)
#define getii(a, b) scanf("%d %d", &a, &b)
#define getiii(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pf printf
#define sc scanf
#define rep(a, b, x) for(int x = a;x < b;x++)
#define reu(a, b, x) for(int x = a;x <= b;x++)
#define pi pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define pq priority_queue
using namespace std;
vi graph[200005];
vector<vector<int> >cc;
bool marq[200005] = {};
int color[200005];
void dfs(int v, int pos);
bool comp(int a, int b);
int main()
{
	int n, m, k;
	getiii(n, m, k);
	reu(1, n, i)
		geti(color[i]);
	int v1, v2;
	rep(0, m, i)
	{
		getii(v1, v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	reu(1, n, i)
	{
		if(marq[i] == false)
		{
			cc.push_back(vector<int>());
			cc[cc.size()-1].push_back(i);
			dfs(i, cc.size()-1);
		}
	}
	int cont = 0;
	rep(0, cc.size(), i)
	{
		sort(cc[i].begin(), cc[i].end(), comp);
		int m = 0, qt = 0, ant = -1;
		rep(0, cc[i].size(), j)
		{
			if(ant != color[cc[i][j]])
			{
				qt = 1;
				ant = color[cc[i][j]];
			}
			else
			{
				qt++;
			}
			m = max(m, qt);
		}
		cont += cc[i].size() - m;
	}
	printf("%d\n", cont);
	return 0;
}
void dfs(int v, int pos)
{
	marq[v] = true;
	rep(0, graph[v].size(), i)
	{
		int u = graph[v][i];
		if(!marq[u])
		{
			cc[pos].push_back(u);
			dfs(u, pos);
		}
	}
}
bool comp(int a, int b)
{
	if(color[a] == color[b])
		return a < b;
	return color[a] < color[b];
}
