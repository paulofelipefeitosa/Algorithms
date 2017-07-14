#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
struct cttt
{
	int c1, c2, c3;
};
cttt rank[MAX];
int n, bit[MAX];
bool comp(cttt a, cttt b);
int query(int r);
void update(int i, int v);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d %d %d", &rank[i].c1, &rank[i].c2, &rank[i].c3);
			bit[i] = 1<<30;
		}
		sort(rank+1, rank+1+n, comp);
		//menor aparição possível de [1, rank[i].c1]
		
		int cont = n;
		for(int i = 1;i <= n;i++)
		{
			int less = query(rank[i].c2);
			if(less < rank[i].c3)
				cont--;
			update(rank[i].c2, rank[i].c3);
		}
		
		printf("%d\n", cont);
	}
	return 0;
}
int query(int r)
{
	int ans = 1<<30;
	while(r)
	{
		ans = min(ans, bit[r]);
		r -= r & (-r);
	}
	return ans;
}
void update(int i, int v)
{
	while(i <= n)
	{
		bit[i] = min(bit[i], v);
		i += i & (-i);
	}
}
bool comp(cttt a, cttt b)
{
	if(a.c1 == b.c1)
	{
		if(a.c2 == b.c2)
			return a.c3 < b.c3;
		return a.c2 < b.c2;
	}
	return a.c1 < b.c1;
}
