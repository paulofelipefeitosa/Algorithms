#include <bits/stdc++.h>
#define MAX  100005
#define MAXS 325
#define MAXQ 100005
using namespace std;
int a[MAX], n, q, s;
int qi[MAXQ], qj[MAXQ], p[MAXQ], ans[MAXQ];
int occur[MAX] = {};
vector<int>group[MAXS];
bool comp(int a, int b);
bool comp2(int a, int b);
int main()
{
	scanf("%d %d", &n, &q);
	for(int i = 0;i < n;i++)
		scanf("%d", &a[i]);
	s = sqrt(n);
	if(s*s < n)
		s++;
	for(int i = 0;i < q;i++)
	{
		scanf("%d %d", &qi[i], &qj[i]);
		qi[i]--; qj[i]--;
		p[i] = i;
	}
	sort(p, p+q, comp);
	for(int i = 0;i < q;i++)
	{
		int gp = qi[p[i]]/s;
		group[gp].push_back(p[i]);
	}
	for(int i = 0;i < s;i++)
		sort(group[i].begin(), group[i].end(), comp2);
	int l = 0, r = 0, cont = 0;
	bool flag = false;
	for(int i = 0;i < s;i++)
	{
		for(int j = 0;j < group[i].size();j++)
		{
			int ql = qi[group[i][j]], qr = qj[group[i][j]];
			if(!flag)
			{
				for(int k = ql;k <= qr;k++)
					if(a[k] <= 100000)
					{
						if(occur[a[k]] == a[k])
							cont--;
						occur[a[k]]++;
						if(occur[a[k]] == a[k])
							cont++;
					}
				l = ql; r = qr;
				flag = true;
			}
			else
			{
				if(l < ql)
				{
					for(int k = l;k < ql;k++)
						if(a[k] <= 100000)
						{
							if(occur[a[k]] == a[k])
								cont--;
							occur[a[k]]--;
							if(occur[a[k]] == a[k])
								cont++;
						}
				}
				else if(l > ql)
				{
					for(int k = l-1;k >= ql;k--)
						if(a[k] <= 100000)
						{
							if(occur[a[k]] == a[k])
								cont--;
							occur[a[k]]++;
							if(occur[a[k]] == a[k])
								cont++;
						}
				}
				l = ql;
				if(r < qr)
				{
					for(int k = r+1;k <= qr;k++)
						if(a[k] <= 100000)
						{
							if(occur[a[k]] == a[k])
								cont--;
							occur[a[k]]++;
							if(occur[a[k]] == a[k])
								cont++;
						}
				}
				else if(r > qr)
				{
					for(int k = r;k > qr;k--)
						if(a[k] <= 100000)
						{
							if(occur[a[k]] == a[k])
								cont--;
							occur[a[k]]--;
							if(occur[a[k]] == a[k])
								cont++;
						}
				}
				r = qr;
			}
			ans[group[i][j]] = cont;
		}
	}
	for(int i = 0;i < q;i++)
		printf("%d\n", ans[i]);
	return 0;
}
bool comp(int a, int b)
{
	return qi[a] < qi[b];
}
bool comp2(int a, int b)
{
	return qj[a] < qj[b];
}
