#include <bits/stdc++.h>
#define MAX 22
using namespace std;
vector<int>lista[15];
int reach[MAX], vec[MAX], ans[MAX], peso[15];
int main()
{
	int n, w, tot, cont, m, qnt, p, sum, maxx, out = 1, num;
	while(scanf("%d %d", &n, &w), n || w)
	{
		for(int i=0;i<n;i++)
			scanf("%d", &reach[i]);
		scanf("%d", &m);
		for(int i=0;i<m;i++)
		{
			scanf("%d", &qnt);
			while(qnt--)
			{
				scanf("%d", &num);
				lista[i].push_back(num-1);
			}
			scanf("%d", &peso[i]);
		}
		tot = 1<<n; maxx = 0;
		for(int bit = 0;bit < tot;bit++)
		{
			cont = 0;
			for(int i=0;i<n;i++)
				if(bit & (1<<i))
					vec[cont++] = i;
			if(cont == w)
			{
				sum = 0;
				for(int i=0;i<cont;i++)
					sum += reach[vec[i]];
				for(int i=0;i<m;i++)
				{
					num = 0;
					for(int j=0;j<cont;j++)
						if(binary_search(lista[i].begin(), lista[i].end(), vec[j]))
							num++;
					if(num > 1)
						sum -= peso[i]*(num-1);
				}		
				if(sum > maxx)
				{
					maxx = sum;
					for(int i=0;i<cont;i++)
						ans[i] = vec[i];
				}
				else if(sum == maxx)
				{
					bool sol = false;
					for(int i=0;i<cont && !sol;i++)
						if(vec[i]<ans[i])
							sol = true;
					if(sol)
						for(int i=0;i<cont;i++)
							ans[i] = vec[i];
				}
			}
		}
		printf("Case Number  %d\nNumber of Customers: %d\nLocations recommended:", out++, maxx);
		for(int i=0;i<w;i++)
			printf(" %d", ans[i]+1);
		printf("\n\n");
		
		for(int i=0;i<m;i++)
			lista[i].clear();
	}
	return 0;
}
