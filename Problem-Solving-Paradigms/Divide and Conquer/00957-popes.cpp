#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int main()
{
	int y, p;
	int timee[MAX], jl, ju, lim;
	int maxx, v1, v2;
	while(scanf("%d", &y)!=EOF)
	{
		scanf("%d", &p);
		for(int i=0;i<p;i++)
			scanf("%d", &timee[i]);
		maxx = 0;
		for(int i=0;i<p;i++)
		{
			lim = timee[i] + y - 1;
			ju = upper_bound(timee+i, timee+p, lim) - timee;
			if(ju == p || timee[ju] > lim)
				ju--;
			if((ju -i + 1) > maxx)
			{
				maxx = ju - i + 1;
				v1 = i;
				v2 = ju;
			}
		}
		printf("%d %d %d\n", maxx, timee[v1], timee[v2]);
	}
	return 0;
}
