#include <bits/stdc++.h>
using namespace std;
int t, n, vet[15], ans[15], used = 0;
bool sol;
void backtrack(int cont, int val, int i);
int main()
{
	while(scanf("%d %d", &t, &n), n)
	{
		int sum = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &vet[i]);
			sum += vet[i];
		}
		printf("Sums of %d:\n", t);
		if(sum < t)
			puts("NONE");
		else if(sum == t)
		{
			printf("%d", vet[0]);
			for(int i = 1;i < n;i++)
				printf("+%d", vet[i]);
			putchar('\n');
		}
		else
		{
			sol = false;
			backtrack(0, 0, 0);
			if(!sol)
				puts("NONE");
		}
	}
	return 0;
}
void backtrack(int cont, int val, int i)
{
	if(val == t)
	{
		printf("%d", ans[0]);
		for(int i = 1;i < cont;i++)
			printf("+%d", ans[i]);
		putchar('\n');
		sol = true;
		return;
	}
	int ant = -1;
	for(int j = i;j < n;j++)
		if(!(used & (1<<j)) && ant != vet[j])
		{
			used |= (1<<j);
			ans[cont] = vet[j];
			backtrack(cont+1, val + vet[j], j+1);
			used &= ~(1<<j);
			ant = vet[j];
		}
}
