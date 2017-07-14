#include <bits/stdc++.h>
#define MAX 100005
#define MAXS 365
using namespace std;
int a[MAX], ord[MAX], sum[MAXS], s, n;
vector<int>group[MAXS], upd[MAXS];
void build();
int main()
{
	int q;
	scanf("%d %d", &n, &q);
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &a[i]);
		ord[i] = a[i];
	}
	sort(ord, ord+n);
	s = sqrt(n);
	if(s*s < n)
		s++;
	build();
	char op[2];
	int k = 0;
	for(int i = 0;i < q;i++)
	{
		scanf("%s", op);
		if(op[0] == 'C')
		{
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			
		}
		else
		{
			int i, x;
			scanf("%d %d", &i, &x);
			
		}
	}
	return 0;
}
void build()
{
	int l = 0, r = s;
	for(int i = 0;i < s;i++, l+=s, r+=s)
	{
		group[i].resize(min(r-l, n-l), 1);
		sum[i] = min(r-l, n-l);
	}
}
void update(int i, int x)
{
	int gp = i/s;
	upd[]
}
