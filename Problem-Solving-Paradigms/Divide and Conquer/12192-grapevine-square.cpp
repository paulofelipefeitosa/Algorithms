#include <bits/stdc++.h>
#define MAX 505
using namespace std;
int field[MAX][MAX];
int main()
{
	int n, m, q;
	int lb, ub;
	int il;
	int max_size;
	int row_end, col_end;
	while(scanf("%d %d", &n, &m), n || m)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d", &field[i][j]);
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &lb, &ub);
			max_size = 0;
			for(int i=0;i<n;i++)
			{
				il = lower_bound(field[i], field[i]+m, lb) - field[i];
				for(int d_size = max_size;d_size < n;d_size++)
				{
					row_end = i + d_size;
					col_end = il + d_size;
					if(row_end >= n || col_end >= m || field[row_end][col_end] > ub)
						break;
					if(d_size + 1 > max_size)
						max_size = d_size + 1;
				}
			}
			printf("%d\n", max_size);
		}
		puts("-");
	}
	return 0;
}
