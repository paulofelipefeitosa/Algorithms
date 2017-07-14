#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
int vessels[MAX];
int n, m;
bool simulate(int cap);
int main()
{
	int lb, ub, mid;
	int ans;
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		lb = 0; ub = 1000000000;
		for(int i=0;i<n;i++)
		{
			scanf("%d", &vessels[i]);
			lb = max(vessels[i], lb);
		}
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
		printf("%d\n", ans);
	}
	return 0;
}
bool simulate(int cap)
{
	int count = 1, act = 0;
	for(int i=0;i<n;i++)
	{
		if(act + vessels[i] > cap)
		{
			count++;
			act = vessels[i];
		}
		else
			act += vessels[i];
		if(count > m)
			return false;
	}
	return true;
}
