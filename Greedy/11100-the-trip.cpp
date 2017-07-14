#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
int n, bag[MAX];
int sol[MAX][MAX], point[MAX];
bool simulate(int k);
void reconstruct(int k);
int main()
{
	bool end = false;
	while(scanf("%d", &n), n)
	{
		if(end)
			putchar('\n');
		else
			end = true;
		for(int i = 0;i < n;i++)
			scanf("%d", &bag[i]);
		sort(bag, bag+n);
		int l = 1, r = n, mid, ans = 1<<30;
		while(l <= r)
		{
			mid = (l+r)>>1;
			if(simulate(mid))
			{
				r = mid - 1;
				ans = min(ans, mid);
			}
			else
				l = mid + 1;
		}
		reconstruct(ans);
		printf("%d\n", ans);
		for(int i = 0;i < ans;i++)
		{
			printf("%d", sol[i][0]);
			for(int j = 1;j <= point[i];j++)
				printf(" %d", sol[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
bool simulate(int k)
{
	for(int i = n-1, j = 0;i >= n-k;i--, j++)
	{
		sol[j][0] = bag[i];
		point[j] = 0;
	}
	int pos;
	for(int i = n-k-1, j = 0;i >= 0;i--, j++)
	{
		pos = j%k;
		if(sol[pos][point[pos]] > bag[i])
			sol[pos][++point[pos]] = bag[i];
		else
			return false;
	}
	return true;
}
void reconstruct(int k)
{
	for(int i = n-1, j = 0;i >= n-k;i--, j++)
	{
		sol[j][0] = bag[i];
		point[j] = 0;
	}
	int pos;
	for(int i = n-k-1, j = 0;i >= 0;i--, j++)
	{
		pos = j%k;
		sol[pos][++point[pos]] = bag[i];
	}
}
