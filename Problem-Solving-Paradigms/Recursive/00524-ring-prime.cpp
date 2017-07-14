#include <bits/stdc++.h>
using namespace std;
int ans[20], n, used;
bool prime[50] = {};
void crivo(int n);
void backtrack(int cont);
int main()
{
	crivo(35);
	int cont = 1;
	while(scanf("%d", &n) != EOF)
	{
		if(cont > 1)
			putchar('\n');
		printf("Case %d:\n", cont++);
		ans[0] = 1;
		used = 3;
		backtrack(1);
	}
	return 0;
}
void backtrack(int cont)
{
	if(n == cont)
	{
		printf("%d", ans[0]);
		for(int i = 1;i < n;i++)
			printf(" %d", ans[i]);
		putchar('\n');
		return;
	}
	for(int j = 2;j <= n;j++)
		if(!(used & (1<<j)))
		{
			if(prime[ans[cont-1]+j])
				continue;
			if(n-1 == cont && prime[ans[0]+j])
				continue;
			ans[cont] = j;
			used |= (1<<j);
			backtrack(cont+1);
			used &= ~(1<<j);
		}
}
void crivo(int n)
{
    prime[0] = prime[1] = true;
    int cur = 2, endd = sqrt(n) + 1, sieve = 0;
    while(cur < endd)
    {
        if(!prime[cur])
        {
            for(int i = cur; ;i++)
            {
                sieve = i * cur;
                if(sieve > n)
                    break;
                if(!prime[sieve])
                    prime[sieve] = true;
            }
        }
        cur++;
	}
}
