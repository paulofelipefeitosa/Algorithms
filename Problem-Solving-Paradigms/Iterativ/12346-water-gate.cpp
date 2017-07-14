#include <bits/stdc++.h>
#define lld long long int
#define INF 10101010101010
using namespace std;
int main()
{
	pair<lld, lld>gate[25];
	int n;
	
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%lli %lli", &gate[i].first, &gate[i].second);
		
	int m, tam = 1<<n;
	lld minn, v, h, flow, cust;
	scanf("%d", &m);
	
	for(int k = 1;k <= m;k++)
	{
		scanf("%lli %lli", &v, &h);
		minn = INF;
		for(int sub = 0;sub < tam;sub++)
		{
 			flow = 0;
 			cust = 0;
			for(int i = 0;i < n;i++)
				if(sub & (1<<i))
				{
					flow += gate[i].first;
					cust += gate[i].second;
				}
			if(flow * h >= v)
				minn = min(minn, cust);
		}
		if(minn == INF)
			printf("Case %d: IMPOSSIBLE\n", k);
		else
			printf("Case %d: %lli\n", k, minn);
	}
	return 0;
}
