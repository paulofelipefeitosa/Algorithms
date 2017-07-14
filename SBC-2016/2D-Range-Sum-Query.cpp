#include <bits/stdc++.h>
#define MAX 505
using namespace std;
int preta[MAX][MAX] = {}, branca[MAX][MAX] = {}, sump[MAX][MAX] = {}, sumb[MAX][MAX] = {};
int main()
{
	int n, p;
	
	scanf("%d %d", &n, &p);
	
	int i, j;
	for(int k = 0;k < p;k++)
	{
		scanf("%d %d", &i, &j);
		preta[i][j] = 1;
	}
	for(int k = 0;k < p;k++)
	{
		scanf("%d %d", &i, &j);
		branca[i][j] = 1;
	}
	
	for(i = 1;i <= n;i++)
		for(j = 1;j <= n;j++)
		{
			sump[i][j] = sump[i][j-1] + sump[i-1][j] + preta[i][j] - sump[i-1][j-1];
			sumb[i][j] = sumb[i][j-1] + sumb[i-1][j] + branca[i][j] - sumb[i-1][j-1];
		}
	
	int x1, y1, contp = 0, contb = 0;
	int valb, valp;
	for(int x0 = 1;x0 <= n;x0++)
		for(int y0 = 1;y0 <= n;y0++)
			for(int r = 0;r < n;r++)
			{
				x1 = x0 + r;
				y1 = y0 + r;
				if(x1 > n || y1 > n)
					break;
					
				valp = sump[x1][y1] - sump[x0-1][y1] - sump[x1][y0-1] + sump[x0-1][y0-1];
				valb = sumb[x1][y1] - sumb[x0-1][y1] - sumb[x1][y0-1] + sumb[x0-1][y0-1];
				
				if(valp && valb)
					break;
				else if(valp && !valb)
					contp++;
				else if(!valp && valb)
					contb++;
			}
	
	printf("%d %d\n", contp, contb);
	
	return 0;
}		

