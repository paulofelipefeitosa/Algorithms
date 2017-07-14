#include <bits/stdc++.h>
#define MAX 1005
#define fi first
#define se second
using namespace std;
pair<int, int>inter[MAX];
int main()
{
	int n, d, caso = 1;
	while(scanf("%d %d", &n, &d), (n || d))
	{
		bool flag = true;
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d", &inter[i].fi, &inter[i].se);
			if(inter[i].se > d)
				flag = false;
		}
		if(!flag)										/* P(x, y)  */
		{												/*   / \ 	*/
			printf("Case %d: -1\n", caso++);			/*	/	\ 	*/
			continue;									/*a-dx  a+dx*/
		}
		sort(inter, inter+n);
		int cont = 0;
		double dx, clx, crx, lx = -110110110.0, rx = -110110110.0;
		for(int i = 0;i < n;i++)
		{
			dx = sqrt(((double)d*d) - ((double)inter[i].se*inter[i].se));
			clx = inter[i].fi - dx;
			crx = inter[i].fi + dx;
			if(clx <= rx && crx >= lx)///sempre o que está dentro da intersecção do k pontos anteriores
			{
				lx = max(lx, clx);
				rx = min(rx, crx);
			}
			else
			{
				cont++;
				lx = clx;
				rx = crx;
			}
		}
		printf("Case %d: %d\n", caso++, cont);
	}
	return 0;
}
