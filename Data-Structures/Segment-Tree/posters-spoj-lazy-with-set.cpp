#include <bits/stdc++.h>
#define lf(x) x<<1
#define rg(x) x<<1|1
#define MAX 10000000
using namespace std;
int lazy[MAX<<2] = {}, mx = 0;
set<int>cont;
void cnt(int p, int l, int r);
void update(int p, int l, int r, int ul, int ur, int c);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, c = 1;
		scanf("%d", &n);
		while(n--)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			update(1, 1, MAX, l, r, c++);
		}
		cnt(1, 1, MAX);
		printf("%d\n", (int)cont.size());
		for(int i = 1;i <= mx;i++)
			lazy[i] = 0;
		mx = 0;
		cont.clear();
	}
	return 0;
}
void update(int p, int l, int r, int ul, int ur, int c)
{
	mx = max(mx, p);
	if(l > ur || r < ul)
		return;
	if(l >= ul && r <= ur)
		lazy[p] = c;
	else
	{
		int mid = (l+r)>>1;
		if(lazy[p] > 0)		//sempre será um intervalo de tamanhho > 1
			lazy[lf(p)] = lazy[rg(p)] = lazy[p];
		lazy[p] = -1;		//Indica que tem filhos explorados, nao eh completo
		update(lf(p), l, mid, ul, ur, c);
		update(rg(p), mid+1, r, ul, ur, c);
	}
}
void cnt(int p, int l, int r)
{
	if(lazy[p] == 0)
		return;
	mx = max(mx, p);
	if(lazy[p] > 0)
		cont.insert(lazy[p]);
	else
	{
		int mid = (l+r)>>1;
		cnt(lf(p), l, mid);
		cnt(rg(p), mid+1, r);
	}
}
