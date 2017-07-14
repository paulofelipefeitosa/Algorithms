#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int matrix[MAX][MAX], sum[MAX][MAX] = {};
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
		{
			scanf("%d", &matrix[i][j]);
			sum[i][j] = matrix[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
		}
	
	int maxx = -127*100*100, sum_cur;
	for(int x0 = 1;x0 <= n;x0++)
		for(int y0 = 1;y0 <= n;y0++)
			for(int x1 = x0;x1 <= n;x1++)
				for(int y1 = y0;y1 <= n;y1++)
				{
					sum_cur = sum[x1][y1] - sum[x0-1][y1] - sum[x1][y0-1] + sum[x0-1][y0-1];
					maxx = max(maxx, sum_cur);
				}
	
	printf("%d\n", maxx);
	return 0;
}
