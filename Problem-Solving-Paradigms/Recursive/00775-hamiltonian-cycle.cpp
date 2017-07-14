#include <bits/stdc++.h>
using namespace std;
int n, ans[260];
bool graph[260][260] = {}, used[260] = {};
bool backtrack(int cont);
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		int v1, v2;
		while(getchar() == '\n')
		{
			scanf("%d %d", &v1, &v2);
			graph[v1][v2] = true;
			graph[v2][v1] = true;
		}
		
		if(backtrack(0))
		{
			for(int i = 0;i < n;i++)
				printf("%d ", ans[i]);
			printf("%d\n", ans[0]);
		}
		else
			puts("N");
		
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				graph[i][j] = false;
	}
	return 0;
}
bool backtrack(int cont)
{
	if(cont == n)
	{
		if(graph[ans[0]][ans[cont-1]])
			return true;
		return false;
	}
	for(int i = 1;i <= n;i++)
		if(!used[i] && (cont == 0 || graph[ans[cont-1]][i]))
		{
			used[i] = true;
			ans[cont] = i;
			if(backtrack(cont+1))
			{
				used[i] = false;
				return true;
			}
			used[i] = false;
		}
	return false;
}
