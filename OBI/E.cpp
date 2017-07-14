#include <bits/stdc++.h>
int mat[1005][1005], cpy[1005][1005];
int lin, col;
using namespace std;
int main()
{
	int m, n, cont = 1;
	while(scanf("%d %d", &m, &n), (m || n))
	{
		cout<<"Teste "<<cont++<<endl;
		lin = col = 0;
		for(int i = 0;i < m;i++)
		{
			for(int j = 0;j < n;j++)
				scanf("%d", &mat[i][j]);
		}
		int x, y;
		while(scanf("%d %d", &x, &y), (x || y))
		{
			col += x;
			lin += y;
		}
		lin = -lin;
		lin = lin % m;
		col = col % n;
		if(lin < 0)
			lin = m + lin;
		if(col < 0)
			col = n + col;
		//printf("%d %d\n", lin, col);
		for(int i = 0, k = lin;i < m;i++, k++)
		{
			k = k % m;
			for(int j = 0, l = col;j < n;j++, l++)
			{
				l = l % n;
				cpy[k][l] = mat[i][j];
			}
		}
		for(int i = 0;i < m;i++)
		{
			printf("%d", cpy[i][0]);
			for(int j = 1;j < n;j++)
				printf(" %d", cpy[i][j]);
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
