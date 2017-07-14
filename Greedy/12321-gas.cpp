#include <bits/stdc++.h>
#define MAX 10005
#define fi first
#define se second
using namespace std;
pair<int, int>inter[MAX];
int main()
{
	int l, n;
	while(scanf("%d %d", &l, &n), (l || n))
	{
		int x, r;
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d", &x, &r);
			inter[i].fi = x - r;
			inter[i].se = x + r;
		}
		sort(inter, inter+n);
		int cont = 0, i = 0;
		int required = 0, rReach = 0, best;
		bool have;
		while(rReach < l)
		{
			best = required;
			have = false;
			for(;i < n;i++)
			{
				if(inter[i].fi > required)
					break;
				if(inter[i].se >= best)
				{
					best = inter[i].se;
					have = true;
				}
			}
			if(!have)
				break;
			cont++;
			required = rReach = best;
		}
		if(rReach < l)
			puts("-1");
		else
			printf("%d\n", n - cont);
	}
	return 0;
}
