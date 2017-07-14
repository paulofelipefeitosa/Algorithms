#include <bits/stdc++.h>
#define MAX 256
using namespace std;
int sum[MAX][MAX] = {}, n, m, l;
int vet[MAX], bit[MAX];
int query(int i);
void update(int i);
int main()
{
    scanf("%d %d", &n, &m);
    int num;
    for(int i = 1;i <= n;i++)
    	for(int j = 1;j <= m;j++)
    	{
    		scanf("%d", &num);
    		sum[i][j] = sum[i-1][j] + sum[i][j-1] + num - sum[i-1][j-1];
 		}
    
    int a, b;
    long long int ans = 0;
    scanf("%d %d", &a, &b);
    for(int i = 1;i <= n;i++)
    {
		for(int k = 0;k < i;k++)
		{
			for(l = 0;l <= m;l++)
			{
				vet[l+1] = sum[k][l] - sum[i][l];
				bit[l+1] = 0;
			}
			l = m+1;
			sort(vet+1, vet+l);
			
			for(int j = 1;j <= m;j++)
			{
				int posj = lower_bound(vet+1, vet+l, sum[k][j-1] - sum[i][j-1]) - vet;
				update(posj);
				
				int x = a - sum[i][j] + sum[k][j];
				int y = b - sum[i][j] + sum[k][j];
				int posx = lower_bound(vet+1, vet+l, x) - vet;
				int posy = upper_bound(vet+1, vet+l, y) - vet;
				if(vet[posy] > y || posy == l)
					posy--;

				if(posx <= posy)
					ans += query(posy) - query(posx-1);
			}
		}
    }
    printf("%lld\n", ans);
    return 0;
}
int query(int i)
{
	int sum = 0;
	while(i)
	{
		sum += bit[i];
		i -= i & (-i);
	}
	return sum;
}
void update(int i)
{
	while(i < l)
	{
		bit[i]++;
		i += i & (-i);
	}
}
