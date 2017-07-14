#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
//only give the length
int main()
{
	int A[MAX], n;
	
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", &A[i]);
	
	int L[MAX], pt = 0;
	L[pt++] = A[0];
	for(int i = 1;i < n;i++)
	{
		int pos = lower_bound(L, L+pt, A[i]) - L;
		if(pos == pt)
			L[pt++] = A[i];
		else
			L[pos] = min(L[pos], A[i]);
	}
	printf("Length = %d\n", pt);
	return 0;
}
