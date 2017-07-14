#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int degree[MAX] = {};
vector<int>path;
multiset<int>graph[MAX];
map<pair<int,int>, int>idx;
pair<int,int>edge[MAX<<2];
void dfs(int v);
bool euler_check(int n);
bool bfs(int u, int n);
int main()
{
	int n, e;
	scanf("%d%d", &n, &e);
	for(int i = 0;i < e;i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		graph[u].insert(v);
		graph[v].insert(u);
		degree[u]++;
		degree[v]++;
		edge[i] = make_pair(u, v);
		idx[make_pair(u, v)] = i;
		idx[make_pair(v, u)] = i;
	}
	if(bfs(1, n) && euler_check(n))
	{
		puts("YES");
		dfs(1);
		for(int i = 0;i < (path.size() - 1);i++)
			edge[idx[make_pair(path[i], path[i+1])]] = make_pair(path[i], path[i+1]);
		for(int i = 0;i < e;i++)
			printf("%d %d\n", edge[i].second, edge[i].first);
	}
	else
		puts("NO");
	return 0;
}
void dfs(int v)
{
	while(!graph[v].empty())
	{
		int to = (*graph[v].begin());
		graph[v].erase(to);
		graph[to].erase(v);
		dfs(to);
	}
	path.push_back(v);
}
bool euler_check(int n)
{
	for(int i = 1;i <= n;i++)
		if(degree[i] & 1)
			return false;
	return true;
}
bool bfs(int u, int n)
{
	vector<bool>marq(n+1, false);
	queue<int>fila;
	int count = 1;
	fila.push(u);
	marq[u] = true;
	while(!fila.empty())
	{
		u = fila.front();
		fila.pop();
		for(int v : graph[u])
			if(!marq[v])
			{
				marq[v] = true;
				fila.push(v);
				count++;
			}
	}
	if(count == n)
		return true;
	else
		return false;
}