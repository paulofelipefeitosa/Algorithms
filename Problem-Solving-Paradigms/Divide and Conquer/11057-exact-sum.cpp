#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
int main()
{
	int vet[MAX], n, money, ans1, ans2, diff, val;
	while(scanf("%d", &n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d", &vet[i]);
		scanf("%d", &money);
		sort(vet, vet+n);
		diff = 1<<30;
		for(int i=0;i<n;i++)
		{
			val = money - vet[i];
			if(binary_search(vet, vet+n, val) && abs(val - vet[i]) < diff)
			{
				diff = abs(val - vet[i]);
				ans1 = vet[i];
				ans2 = val;
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", min(ans1, ans2), max(ans1, ans2));
	}
	return 0;
}
