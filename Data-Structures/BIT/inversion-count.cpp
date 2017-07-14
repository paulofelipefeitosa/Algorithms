#include <bits/stdc++.h>
#define lsone(x) x & (-x)
#define MAX 200005
using namespace std;
int n;
int bit[MAX], p[MAX], v[MAX];
long long int query(int l, int r);
long long int sum(int i);
void update(int i, int val);
bool comp(int a, int b);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", &v[i]);
			p[i] = i;
			bit[i] = 0;
		}
		sort(p+1, p+1+n, comp);
		for(int i = 1;i <= n;i++)
			v[p[i]] = i;
		long long int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			ans += query(v[i], n);
			update(v[i], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
long long int query(int l, int r)
{
	return sum(r) - sum(l-1);
}
long long int sum(int i)
{
	long long int sum = 0;
	while(i > 0)
	{
		sum += bit[i];
		i -= lsone(i);
	}
	return sum;
}
void update(int i, int val)
{
	while(i <= n)
	{
		bit[i] += val;
		i += lsone(i);
	}
}
bool comp(int a, int b)
{
	return v[a] < v[b];
}
