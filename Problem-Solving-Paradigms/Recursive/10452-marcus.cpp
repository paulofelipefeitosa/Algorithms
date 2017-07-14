#include <bits/stdc++.h>
using namespace std;
bool marq[10][10];
char mat[10][10], path[100], adj[] = {'A', 'E', 'H', 'I', 'O', 'V', '\0'};
int ci[] = {-1, 0, 0}, cj[] = {0, -1, 1}, n, m, tam;
bool dfs(int i, int j, int cont);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		int x0, y0;
		for(int i = 0;i < n;i++)
		{
			scanf("%s", mat[i]);
			for(int j = 0;j < m;j++)
			{
				if(mat[i][j] == '@')
				{
					x0 = i;
					y0 = j;
				}
				marq[i][j] = false;
			}
		}
		dfs(x0, y0, 0);
		for(int i = 0;i <= tam;i++)
		{
			if(i)
				putchar(' ');
			if(path[i] == 0)
				printf("forth");
			else if(path[i] == 1)
				printf("left");
			else
				printf("right");
		}
		putchar('\n');
	}
	return 0;
}
bool dfs(int i, int j, int cont)
{
	marq[i][j] = true;
	int ii, jj;
	for(int k = 0;k < 3;k++)
	{
		ii = i + ci[k];
		jj = j + cj[k];
		if(ii >= 0 && jj < m && jj >= 0 && !marq[ii][jj])
		{
			if(mat[ii][jj] == '#')
			{
				path[cont] = k;
				tam = cont;
				return true;
			}
			if(binary_search(adj, adj+6, mat[ii][jj]))
			{
				path[cont] = k;
				if(dfs(ii, jj, cont+1))
					return true;
			}
		}
	}
	return false;
}
