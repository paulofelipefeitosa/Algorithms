#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int diff[MAX], n;
bool simulate(int k);
int main()
{
	int t, lb, ub, mid, ans, ant, num, maxx;
	scanf("%d", &t);
	for(int k=1;k<=t;k++)
	{
		scanf("%d", &n);
		maxx = ant = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d", &num);
			diff[i] = num - ant;
			ant = num;
			maxx = max(maxx, diff[i]);
		}
		if(simulate(maxx))
			printf("Case %d: %d\n", k, maxx);
		else
			printf("Case %d: %d\n", k, maxx+1);
		/*	BINARY SEARCH
		lb = 1; ub = 10000000;
		while(lb <= ub)
		{
			mid = (lb + ub)>>1;
			if(simulate(mid))
			{
				ans = mid;
				ub = mid - 1;
			}
			else
				lb = mid + 1;
		}
		printf("Case %d: %d\n", k, ans);*/
	}
	return 0;
}
bool simulate(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(diff[i] > k)
			return false;
		else if(diff[i] == k)
			k--;
	}
	return true;
}
