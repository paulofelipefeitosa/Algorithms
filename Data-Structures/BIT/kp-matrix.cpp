#include <bits/stdc++.h>
#define MAX 255
using namespace std;
int Msum[MAX][MAX]={}, n, m;
int main()
{
    int num;
    scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d", &num);
			Msum[i][j] = Msum[i-1][j] + Msum[i][j-1] - Msum[i-1][j-1] + num;
		}
	int a, b, sum, cont = 0;
	scanf("%d %d", &a, &b);
	for(int x1 = 1;x1 <= n;x1++)
		for(int y1 = 1;y1 <= m;y1++)
			for(int x2 = x1;x2 <= n;x2++)
				for(int y2 = y1;y2 <= m;y2++)
				{
					sum = Msum[x2][y2] - Msum[x2][y1-1] - Msum[x1-1][y2] + Msum[x1-1][y1-1];
					if(sum >= a && sum <= b)
						cont++;
				}
    printf("%d\n", cont);
    return 0;
}
