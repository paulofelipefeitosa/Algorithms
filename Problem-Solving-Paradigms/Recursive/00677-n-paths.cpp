#include <bits/stdc++.h>
using namespace std;
int graph[15][15], path[10], v, n, used;
bool sol;
void backtrack(int u, int cont);
int main()
{
	while(scanf("%d %d", &v, &n) != EOF)
	{
		for(int i = 1;i <= v;i++)
			for(int j = 1;j <= v;j++)
				scanf("%d", &graph[i][j]);
		
		used = 2;
		sol = false;
		backtrack(1, 0);
		
		if(!sol)
			printf("no walk of length %d\n", n);
		
		if(scanf("%d", &v) != EOF)
			putchar('\n');
	}
	return 0;
}
void backtrack(int u, int cont)
{
	if(n == cont)
	{
		printf("(1");
		for(int i = 0;i < cont;i++)
			printf(",%d", path[i]);
		printf(")\n");
		sol = true;
		return;
	}
	for(int i = 2;i <= v;i++)
	{
		if(!(used & (1<<i)) && graph[u][i])
		{
			path[cont] = i;
			used |= (1<<i);
			backtrack(i, cont+1);
			used &= ~(1<<i);
		}
	}
}

