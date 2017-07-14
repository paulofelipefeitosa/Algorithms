#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int ans[20][20][2];
	string str(20, '0');
	for(int p = 1;p <= 17;p++)
		for(int q = 1;q <= 17;q++)
		{
			int tam = 1<<p, div = 1<<q;
			long long int num, larg = 0, small = 100000000000000000;
			for(int sub = 1;sub < tam;sub++)
			{
				for(int i = 0;i < p;i++)
					if(sub & (1<<i))
						str[p-1-i] = '2';
					else
						str[p-1-i] = '1';
				str[p] = '\0';
				num = stoll(str);
				if(num % div == 0)
				{
					small = min(small, num);
					larg = max(larg, num);
				}
			}
			ans[p][q][0] = small;
			ans[p][q][1] = larg;
		}
	int t, cont = 1;
	scanf("%d", &t);
	while(t--)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		
		printf("Case %d:", cont++);
		if(ans[p][q][0] == ans[p][q][1])
			printf(" %lli\n", ans[p][q][0]);
		else if(ans[p][q][1] == 0)
			printf(" impossible\n");
		else
			printf(" %lli %lli\n", ans[p][q][0], ans[p][q][1]);
	}
	return 0;
}
