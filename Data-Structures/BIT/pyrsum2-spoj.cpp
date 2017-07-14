#include <bits/stdc++.h>
#define left(x) x<<1			
#define right(x) x<<1|1			
#define MAX 1000005
using namespace std;

int tree[MAX<<2] = {}, lazy[MAX<<2] = {}, n = 1000000;

void updateRange(int p, int l, int r, int ul, int ur, int val);
int query(int p, int l, int r, int ql, int qr);

int main()
{
	int q, l, r;
	char s[7];
	scanf("%d", &q);
	while(q--)
	{
		scanf("%s %d %d", &s, &l, &r);
		if(s[0] == 'c')			
			printf("%d\n", query(1, 1, n, l, r));
		else					
		{
			updateRange(1, 1, n, l, r, val);
		}
	}
	return 0;
}
int query(int p, int l, int r, int ql, int qr)
{
	if(lazy[p] != 0)
	{
		tree[p] = (r-l+1)*lazy[p];
		if(l != r)
		{
			lazy[left(p)] = lazy[p];
			lazy[right(p)] = lazy[p];
		}
		lazy[p] = 0;
	}
	
	if(l > qr || r < ql)		//O intervalo do nó está totalmente fora?
		return 0;
	
	if(l >= ql && r <= qr)		//O intervalo do nó está totalmente dentro?
		return tree[p];
	
	int mid = (l+r)>>1;
	return query(left(p), l, mid, ql, qr) + query(right(p), mid+1, r, ql, qr);
}
void updateRange(int p, int l, int r, int ul, int ur, int val)
{
	if(lazy[p] != 0)
	{
		tree[p] = (r-l+1)*lazy[p];
		if(l != r)
		{
			lazy[left(p)] = lazy[p];
			lazy[right(p)] = lazy[p];
		}
		lazy[p] = 0;
	}
	
	if(l > ur || r < ul)
		return;
	
	if(l >= ul && r <= ur)
	{
		tree[p] = (r-l+1)*val;
		if(l != r)
		{
			lazy[left(p)] = val;
			lazy[right(p)] = val;
		}
		return;
	}
	
	int mid = (l+r)>>1;
	updateRange(left(p), l, mid, ul, ur, val);
	updateRange(right(p), mid+1, r, ul, ur, val);
}
