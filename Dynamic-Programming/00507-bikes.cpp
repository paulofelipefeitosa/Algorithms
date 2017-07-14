#include <bits/stdc++.h>
#define MAX 20005
using namespace std;
int main()
{
	int A[MAX], t;
	scanf("%d", &t);
	for(int k = 1;k <= t;k++)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0;i < (n-1);i++)
			scanf("%d", &A[i]);
		
		int sum = 0, ans = 0;
		int l = -1, r = -1, init = 0;
		for(int i = 0;i < (n-1);i++)
		{
			sum += A[i];
			if(sum > ans)
			{
				ans = sum;
				l = init;
				r = i;
			}
			else if(sum == ans)
			{
				if(l == init)
					r = i;
				else if(i-init > r-l)
				{
					l = init;
					r = i;
				}
			}
			
			if(sum < 0)
			{
				sum = 0;
				init = i+1;
			}
		}
	
		if(ans)
			printf("The nicest part of route %d is between stops %d and %d\n", k, l+1, r+2);
		else
			printf("Route %d has no nice parts\n", k);
	}
	return 0;
}
