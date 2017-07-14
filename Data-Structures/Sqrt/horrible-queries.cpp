#include <bits/stdc++.h>
#define MAXA 100005
#define MAX 360
using namespace std;
int gsize[MAX], n, s;
long long int gsum[MAX], lazy[MAX], a[MAXA];
void build();
void update(int l, int r, long long int val);
long long int query(int l, int r);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int q;
		scanf("%d %d", &n, &q);
		s = sqrt(n);
		if(s*s < n)
			s++;
		build();
		while(q--)
		{
			int op;
			scanf("%d", &op);
			if(op == 0)
			{
				int l, r, x;
				scanf("%d %d %d", &l, &r, &x);
				l--; r--;
				update(l, r, x);
			}
			else
			{
				int l, r;
				scanf("%d %d", &l, &r);
				l--; r--;
				printf("%lld\n", query(l, r));
			}
		}
	}
	return 0;
}
void build()
{
	for(int i = 0;i < n;i++)
		a[i] = 0;
	int l = 0, r = s;
	for(int i = 0;i < s;i++, l+=s, r+=s)
	{
		lazy[i] = gsum[i] = 0;
		gsize[i] = min(r-l, n-l);
	}
}
void update(int l, int r, long long int val)
{
	for(int i = l;i <= r;)
	{
		int gp = i/s;
		if(i % s == 0 && i + gsize[gp] - 1 <= r)
		{
			lazy[gp] += val;
			gsum[gp] += val*gsize[gp];
			i += s;
		}
		else
		{
			if(lazy[gp])
			{
				for(int j = gp*s, end = j+gsize[gp];j < end;j++)
					a[j] += lazy[gp];
				lazy[gp] = 0;
			}
			for(int end = (gp*s)+gsize[gp];i < end && i <= r;i++)
			{
				a[i] += val;
				gsum[gp] += val;
			}
		}
	}
}
long long int query(int l, int r)
{
	long long int ans = 0;
	for(int i = l;i <= r;)
	{
		int gp = i/s;
		if(i % s == 0 && i + gsize[gp] - 1 <= r)
		{
			ans += gsum[gp];
			i += s;
		}
		else
		{
			if(lazy[gp])
			{
				for(int j = gp*s, end = j+gsize[gp];j < end;j++)
					a[j] += lazy[gp];
				lazy[gp] = 0;
			}
			for(int end = (gp*s)+gsize[gp];i < end && i <= r;i++)
				ans += a[i];
		}
	}
	return ans;
}
