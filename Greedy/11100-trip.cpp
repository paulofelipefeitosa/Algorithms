#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
int n, bag[MAX];
vector<int>sol[MAX];
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
			for(int j = 1;j < (int)sol[i].size();j++)
				printf(" %d", sol[i][j]);
			putchar('\n');
		}
		for(int i = 0;i < ans;i++)
			sol[i].clear();
	}
	return 0;
}
bool simulate(int k)
{
	priority_queue<int, vector<int>, less<int> >fila;
	int best;
	for(int i = n-1;i >= n-k;i--)
		fila.push(bag[i]);
	for(int i = n-1-k;i >= 0;i--)
	{
		best = fila.top();
		fila.pop();
		if(best > bag[i])
			fila.push(bag[i]);
		else
			return false;
	}
	return true;
}
void reconstruct(int k)
{
	for(int i = n-1, j = 0;i >= 0;i--, j++)
		sol[j%k].push_back(bag[i]);
}
