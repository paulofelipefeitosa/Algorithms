#include <bits/stdc++.h>
#define MAX 100005
#define fi first
#define se second
using namespace std;
int pai[MAX], depth[MAX], sub[MAX], heavy[MAX], chain[MAX], pseg[MAX];
int c_chain = 0, head_chain[MAX];
bool mark[MAX] = {};
vector<pair<int,int> >adj[MAX];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0;i < m;i++)
	{
		int u, v, w;
		scanf("%d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	pai[1] = -1;
	dfs(1, 1);
	return 0;
}
void dfs(int u, int dep)
{
	mark[u] = true;
	depth[u] = dep;
	sub[u] = 1;
	int submx = 0;
	for(auto v : adj[u])
		if(!mark[v.fi])
		{
			dfs(v.fi, dep+1);
			pai[v.fi] = u;
			if(submx < sub[v.fi])
			{
				submx = sub[v.fi];
				heavy[u] = v.fi;
			}
			sub[u] += sub[v.fi];
		}
}
void hld(int u)
{
	if(head_chain[c_chain] == 0)
		head_chain[c_chain] = u;
	chain[u] = c_chain;
	
}
