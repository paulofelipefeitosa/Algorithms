#include <bits/stdc++.h>
using namespace std;
int n, k, maxx;
int vet[40], sol[10];
void backtrack(int cont);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		for(int i = 0;i < n;i++)
			scanf("%d", &vet[i]);
		maxx = 0;
		backtrack(0);
		printf("%d\n", maxx);
	}
	return 0;
}
void backtrack(int cont)
{
	if(cont == k)
	{
		int ans = vet[sol[0]];
		for(int i = 1;i < k;i++)
			ans = ans & vet[sol[i]];
		maxx = max(maxx, ans);
	}
	else
	{
		int init = 0;
		if(cont > 0)
			init = sol[cont-1] + 1;
		for(int i = init;i < n;i++)
		{
			sol[cont] = i;
			backtrack(cont+1);
		}
	}
}
