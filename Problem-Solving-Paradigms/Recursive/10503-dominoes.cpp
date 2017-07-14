#include <bits/stdc++.h>
using namespace std;
int sp, pi, used;
pair<int,int>ans[20], p[20];
bool backtrack(int cont);
int main()
{
	while(scanf("%d", &sp), sp)
	{
		scanf("%d", &pi);
		pi += 2;
		sp++;
		for(int i = 0;i < pi;i++)
			scanf("%d %d", &p[i].first, &p[i].second);
		used = 0;
		ans[0] = p[0];
		if(backtrack(1))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
bool backtrack(int cont)
{
	if(cont == sp)
	{
		if(ans[cont-1].second == p[1].first)
			return true;
		return false;
	}
	for(int i = 2;i < pi;i++)
	{
		if(p[i].first == ans[cont-1].second && !(used & (1<<i)))
		{
			used |= 1<<i;
			ans[cont] = p[i];
			if(backtrack(cont+1))
				return true;
			used &= ~(1<<i);
		}
		if(p[i].second == ans[cont-1].second && !(used & (1<<i)))
		{
			used |= 1<<i;
			ans[cont].first = p[i].second;
			ans[cont].second = p[i].first;
			if(backtrack(cont+1))
				return true;
			used &= ~(1<<i);
		}
	}
	return false;
}
