#include <bits/stdc++.h>
#define MAX 105
using namespace std;
char square[MAX][MAX];
int sum[MAX][MAX]={};
int main()
{
	int n, m, cont;
	while(scanf("%d", &n), n)
	{
		scanf("%d", &m);
		cont = 0;
		for(int i=1;i<=n;i++)
			scanf("%s", square[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + square[i][j-1]-'0';
		for(int x1=1;x1<=n;x1++)
			for(int y1=1;y1<=m;y1++)
				if(square[x1][y1-1]!='0')
					for(int x2=x1;x2<=n;x2++)
						for(int y2=y1;y2<=m;y2++)
							if((x2-x1+1)*(y2-y1+1) == sum[x2][y2] + sum[x1-1][y1-1] - sum[x1-1][y2] - sum[x2][y1-1])
								cont++;
		printf("%d\n", cont);
	}
	return 0;
}
