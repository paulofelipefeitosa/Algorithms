#include <bits/stdc++.h>
#define MAX  100005
#define MAXS 325
#define MAXQ 50005
using namespace std;
int n, q, s;
int aa[MAX], gsize[MAXS];
vector<int>group[MAXS];
void update(int i, int x);
int query(int l, int r, int x);
int main()
{
	scanf("%d %d", &n, &q);
	s = sqrt(n);
	if(s*s < n)
		s++;
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &aa[i]);
		group[i/s].push_back(aa[i]);
	}
	for(int i = 0;i < s;i++)
	{
		sort(group[i].begin(), group[i].end());
		gsize[i] = group[i].size();
	}
	char op[2];
	for(int i = 0;i < q;i++)
	{
		scanf("%s", op);
		if(op[0] == 'C')
		{
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			l--; r--;
			printf("%d\n", query(l, r, x));
		}
		else
		{
			int l, x;
			scanf("%d %d", &l, &x);
			l--;
			update(l, x);
		}
	}
	return 0;
}
int query(int l, int r, int x)
{
	int ans = 0;
	for(int i = l;i <= r;)
	{
		int gp = i/s;
		if(i % s == 0 && i + gsize[gp] - 1 <= r)
		{
			ans += upper_bound(group[gp].begin(), group[gp].end(), x) - group[gp].begin();
			i += s;
		}
		else
		{
			for(int end = (gp*s)+gsize[gp];i < end && i <= r;i++)
				if(aa[i] <= x)
					ans++;
		}
	}
	return ans;
}
void update(int i, int x)
{
	int gp = i/s;
	group[gp].erase(lower_bound(group[gp].begin(), group[gp].end(), aa[i]));
	group[gp].insert(lower_bound(group[gp].begin(), group[gp].end(), x), x);
	aa[i] = x;
}
