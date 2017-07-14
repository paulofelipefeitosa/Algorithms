#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
int main()
{
	int A[MAX], n;
	
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", &A[i]);
	
	int lis[MAX], build[MAX], rec[MAX];
	int max_lis = 0, idx;
	for(int i = 0;i < n;i++)
	{
		lis[i] = 1;
		build[i] = i;
		for(int j = 0;j < i;j++)
		{
			if(A[j] < A[i])
			{
				if(lis[j] + 1 > lis[i])
				{
					lis[i] = lis[j] + 1;
					build[i] = j;
				}
			}
		}
		if(lis[i] > max_lis)
		{
			max_lis = lis[i];
			idx = i;
		}
	}
	
	printf("%d\n{", max_lis);
	int pt = 0;
	while(build[idx] != idx)
	{
		rec[pt++] = A[idx];
		idx = build[idx];
	}
	rec[pt++] = A[idx];
	
	for(int i = pt-1;i > 0;i--)
		printf("%d,", rec[i]);
	printf("%d}\n", rec[0]);
	return 0;
}
