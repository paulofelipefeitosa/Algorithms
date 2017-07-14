#include <bits/stdc++.h>
#define MAX 21
using namespace std;
int vet[MAX], used, tmp, qnt, ans, out;
void solve(int j, int cap);
int main()
{
	while(scanf("%d", &tmp)!=EOF)
	{
		scanf("%d", &qnt);
		for(int i=0;i<qnt;i++)
			scanf("%d", &vet[i]);
		used = ans = 0;
		solve(0, 0);
		for(int i=0;i<qnt;i++)
			if(out & (1<<i))
				printf("%d ", vet[i]);
		printf("sum:%d\n", ans);
	}
	return 0;
}
void solve(int j, int cap)
{
	if(ans == tmp)
		return;
	if(cap > ans)
	{
		ans = cap;
		out = used;
	}
	int sum;
	for(int i=j;i<qnt;i++)
	{
		sum = cap + vet[i];
		if(!(used & (1<<i)) && sum <= tmp)
		{
			used |= (1<<i);
			solve(i+1, sum);
			used &= ~(1<<i);
		}
	}
}
