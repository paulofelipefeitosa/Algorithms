#include <bits/stdc++.h>
#define MAX 105
using namespace std;
pair<int,int>inter[MAX];
int main()
{
	int t, caso = 1;
	char str[MAX];
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		getchar();
		scanf("%s", str);
		int l, r, last = 0, pt = 0;
		for(int i = 0;i < n;i++)
		{
			if(str[i] == '#')
			{
				bool can = false;
				if(i > 0 && str[i-1]=='.')
					l = last, can = true;
				else
					l = last + 1;
				if(i < (n-1) && str[i+1]=='.')
					r = last + 1, can = true;
				else
					r = last;
				if(can)
					inter[pt++] = pair<int,int>(l, r);
			}
			else
			{
				last++;
				if(i > 0 && str[i-1]=='.')
					l = last - 1;
				else
					l = last;
				if(i < (n-1) && str[i+1]=='.')
					r = last + 1;
				else
					r = last;
				inter[pt++] = pair<int,int>(l, r);
			}
		}
		/*for(int i = 0;i < pt;i++)
			printf("(%d, %d)\n", inter[i].first, inter[i].second);
		putchar('\n');*/
		int required = 1, rReach = 0, i = 0, cont = 0;
		while(rReach < last)
		{
			int best = required;
			for(;i < pt;i++)
			{
				if(inter[i].first > required)
					break;
				if(inter[i].second >= best)
					best = inter[i].second;
			}
			cont++;
			required = best + 1;
			rReach = best;
		}
		printf("Case %d: %d\n", caso++, cont);
	}
	return 0;
}
