#include <bits/stdc++.h>
#define MAX  200005
#define MAXS 450
#define MAXA 1000005
using namespace std;
int qi[MAX], qj[MAX];
bool comp(int a, int b);
bool comp2(int a, int b);
bool comp3(int a, int b);
int main()
{
	int n, q, s, p[MAX];
	long long int ans[MAX], occur[MAXA] = {}, a[MAX];
	vector<int>group[MAXS];
	scanf("%d %d", &n, &q);
	for(int i = 0;i < n;i++)
		scanf("%I64d", &a[i]);
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
	{
		if(i & 1)
			sort(group[i].begin(), group[i].end(), comp3);
		else
			sort(group[i].begin(), group[i].end(), comp2);
	}
	int l = 0, r = n-1, m, ql, qr;
	long long int cont = 0, ss;
	for(int k = 0;k < n;k++)
	{
		ss = a[k];
		occur[ss]++;
		cont += ss*(occur[ss]<<1) - ss;
	}
	for(int i = 0;i < s;i++)
	{
		for(int j = 0;j < group[i].size();j++)
		{
			m = group[i][j];
			ql = qi[m]; qr = qj[m];
			if(l < ql)
			{
				for(int k = l;k < ql;k++)
				{
					ss = a[k];
					occur[ss]--;
					cont -= ss*(occur[ss]<<1) + ss;
				}
			}
			else if(l > ql)
			{
				for(int k = l-1;k >= ql;k--)
				{
					ss = a[k];
					occur[ss]++;
					cont += ss*(occur[ss]<<1) - ss;
				}
			}
			l = ql;
			if(r < qr)
			{
				for(int k = r+1;k <= qr;k++)
				{
					ss = a[k];
					occur[ss]++;
					cont += ss*(occur[ss]<<1) - ss;
				}
			}
			else if(r > qr)
			{
				for(int k = r;k > qr;k--)
				{
					ss = a[k];
					occur[ss]--;
					cont -= ss*(occur[ss]<<1) + ss;
				}
			}
			r = qr;
			ans[m] = cont;
		}
	}
	for(int i = 0;i < q;i++)
		printf("%I64d\n", ans[i]);
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
bool comp3(int a, int b)
{
	return qj[a] > qj[b];
}
