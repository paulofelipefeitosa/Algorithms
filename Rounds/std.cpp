#include <bits/stdc++.h>
using namespace std;
int main()
{
	int alpha[20], beta[20];
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, x0;
		scanf("%d %d", &n, &x0);
		for(int i = 0;i <= n;i++)
			scanf("%d", &alpha[i]);
		beta[n-1] = alpha[n];
		for(int i = n-2;i >= 0;i++)
			beta[i] = alpha[i+1] + (beta[i+1]*x0);
		int r = alpha[0] + (beta[0]*x0);
		printf("%d\n", r);
		for(int i = 0;i < n;i++)
			printf("%d ", beta[i]);
		putchar('\n');
	}
	return 0;
}
