#include <bits/stdc++.h>
#define MAX 505
using namespace std;
int field[MAX][MAX];
int main()
{
	int n, m, q;
	int l, u, il, iu, ill, ilu, iuu, iul;
	int max_all, max_now, ii_now, uu_now, ct_now;
	int ll, dd;
	while(scanf("%d %d", &n, &m), n || m)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d", &field[i][j]);
		scanf("%d", &q);
		while(q--)
		{
			max_now = max_all = 0;
			ct_now = 1;
			ii_now = 0; uu_now = m;
			scanf("%d %d", &l, &u);
			for(int i=0;i<n;i++)
			{
				//DEFINING THE INTERVALS BY BINARY SEARCH
				ilu = upper_bound(field[i], field[i]+m, l) - field[i];
				if(ilu == m)
					ilu = m;
				ill = lower_bound(field[i], field[i]+m, l) - field[i];
				if(ill == m)
					ill = m;
				
				if(field[i][ill] >= l)
					il = ill;
				else
					il = ilu;
					
				iuu = upper_bound(field[i], field[i]+m, u) - field[i];
				if(iuu == m)
					iuu = m-1;
				if(iuu > 0 && field[i][iuu] > u)
					iuu--;
				iul = lower_bound(field[i], field[i]+m, u) - field[i];
				if(iul == m)
					iul = m-1;
				if(iul > 0 && field[i][iul] > u)
					iul--;
				
				if(field[i][iuu] <= u)
					iu = iuu;
				else
					iu = iul;
				
				//KADANE ALGORITHM
				ii_now = max(ii_now, il);
				uu_now = min(uu_now, iu);
				max_now = (uu_now - ii_now + 1)*ct_now;
				if(max_now < (iu - il + 1))
				{
					ii_now = il;
					uu_now = iu;
					ct_now = 1;
					max_now = (iu - il + 1);
				}
				else
					ct_now++;
				if(max_now > max_all)
					max_all = max_now;
			}
			printf("%d\n", max_all);
		}
		puts("-");
	}
	return 0;
}
