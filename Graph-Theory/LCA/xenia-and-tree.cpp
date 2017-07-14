#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int d[MAX], depth[MAX], color[MAX];
int main()
{
	
	return 0;
}
void bfs(int u)
{
	for(int i = 1;i <= n;i++)
		depth[i] = d[i] = 0;
	queue<int>fila;
	fila.push(u);
	depth[u] = 1;
	while(!fila.empty())
	{
		int v = fila.front();
	}
}
