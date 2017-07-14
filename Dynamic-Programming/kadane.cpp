#include <bits/stdc++.h>
#define MAX 20005
using namespace std;
int kadane(int A[], int n, int *l, int *r);
int main()
{
	int A[MAX], n;
	
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", &A[i]);
	
	int ans, l, r;
	
	ans = kadane(A, n, &l, &r);
	
	printf("Max Range Sum = %d with [%d, %d]\n", ans, l, r);
	
	return 0;
}
int kadane(int A[], int n, int *l, int *r)
{
	int sum = 0, ans = 0, init = 0;
	for(int i = 0;i < n;i++)
	{
		sum += A[i];
		if(sum > ans)
		{
			ans = sum;
			l = init;
			r = i;
		}
		if(sum < 0)
		{
			sum = 0;
			init = i+1;
		}
	}
	
	if(ans > 0)
		return ans;
	else			//maior elemento entao
	{
		ans = A[0];
		*l = *r = 0;
		for(int i = 1;i < n;i++)
		{
			if(A[i] > ans)
			{
				ans = A[i];
				*l = *r = i;
			}
		}
		return ans;
	}
}
