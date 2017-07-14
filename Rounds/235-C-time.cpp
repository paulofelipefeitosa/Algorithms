#include <bits/stdc++.h>
#define MAX 1000006
using namespace std;
int b[MAX] = {};
char ans[MAX<<1];
int main()
{
	int n, m, ii = 0, ff = 0, pt = 0;
	scanf("%d %d", &n, &m);
	if((n-1) <= m && m <= ((n+1)<<1))
	{
		int i = 0, cont = 0;
		while(m && cont < ((n-1)<<1))
		{
			b[i]++;
			i = (i+1)%(n-1);
			m--;
			cont++;
		}
		while(m && ii < 2)
		{
			ii++;
			m--;
		}
		while(m && ff < 2)
		{
			ff++;
			m--;
		}
		while(ii--)
			ans[pt++] = '1';
		for(int i = 0;i < n;i++)
		{
			ans[pt++] = '0';
			while(b[i]--)
				ans[pt++] = '1';
		}
		while(ff--)
			ans[pt++] = '1';
		ans[pt] = '\0';
		printf("%s\n", ans);
	}
	else
		puts("-1");
	return 0;
}
