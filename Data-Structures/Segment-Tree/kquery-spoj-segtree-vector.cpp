#include <bits/stdc++.h>
#define lf(x) x<<1
#define rg(x) x<<1|1
#define MAX 32800
using namespace std;
int bl = 1;
vector<int>tree[MAX<<1];
void build();
int query(int l, int r, int k);
int main()
{
	int n;
	scanf("%d", &n);
	while(bl < n)
		bl<<=1;
	int num;
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &num);
		tree[bl+i].push_back(num);
	}
	build();
	int q, l, r, k;
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d %d", &l, &r, &k);
		//printf("%d\n", query(l-1, r, k));
	}
	return 0;
}
void build()
{
	for(int i = bl - 1;i > 0;i--)
		merge(tree[lf(i)].begin(), tree[lf(i)].end(), tree[rg(i)].begin(), tree[rg(i)].end(), back_inserter(tree[i]));
}
int query(int l, int r, int k)
{
	int ans = 0;
	for(l += bl, r += bl; l < r; l>>=1, r>>=1)
	{
		if(l & 1)
		{
			ans += tree[l].end() - upper_bound(tree[l].begin(), tree[l].end(), k);
			l++;
		}
		if(r & 1)
		{
			r--;
			ans += tree[r].end() - upper_bound(tree[r].begin(), tree[r].end(), k);
		}
	}
	return ans;
}
