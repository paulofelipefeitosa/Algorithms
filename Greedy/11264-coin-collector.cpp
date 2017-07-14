#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
int coin[MAX];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", &coin[i]);
		long long int sum = coin[0];
		int cont = 1;
		for(int i = 1;i < (n-1);i++)
		{
			if(sum + coin[i] < coin[i+1])
			{
				sum += (long long int)coin[i];
				cont++;
			}
		}
		printf("%d\n", cont+1);
	}
	return 0;
}
