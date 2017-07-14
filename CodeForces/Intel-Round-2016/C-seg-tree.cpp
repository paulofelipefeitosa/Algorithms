#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) x<<1|1
using namespace std;
long long int tree[100005<<2] = {};
long long int query(int p, int l, int r, int ql, int qr);
void updateRange(int p, int l, int r, int ul, int ur, long long int val);
int main()
{
	int n, num;
	long long int sum[100005];
	sum[0] = 0;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &num);
		sum[i] = sum[i-1] + (long long int)num;
	}
	set<pair<int,int> >seg;
	seg.insert(pair<int,int>(1, n));
	updateRange(1, 1, n, 1, n, sum[n]);
	
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &num);
		auto it = seg.lower_bound(pair<int,int>(num, 0));
		pair<int,int>act;
		
		if(it == seg.end())
			act = *(--it);
		if(num < (*it).first || num > (*it).second)
			act = *(--it);
		else
			act = *it;

		updateRange(1, 1, n, num, num, 0);
		seg.erase(it);
		if(num-1 >= act.first)
		{
			seg.insert(pair<int,int>(act.first, num-1));
			updateRange(1, 1, n, act.first, num-1, sum[num-1] - sum[act.first-1]);
		}
		if(num+1 <= act.second)
		{
			seg.insert(pair<int,int>(num+1, act.second));	
			updateRange(1, 1, n, num+1, act.second, sum[act.second] - sum[num]);
		}
		printf("%I64d\n", query(1, 1, n, 1, n));
	}
	return 0;
}
void updateRange(int p, int l, int r, int ul, int ur, long long int val)
{	
	if(l > ur || r < ul)
		return;
	
	if(l >= ul && r <= ur)
		tree[p] = val;
	else
	{
		updateRange(left(p), l, (l+r)>>1, ul, ur, val);
		updateRange(right(p), ((l+r)>>1)+1, r, ul, ur, val);
		tree[p] = max(tree[left(p)], tree[right(p)]);
	}
}
long long int query(int p, int l, int r, int ql, int qr)
{
	if(l > qr || r < ql)
		return 0;
		
	if(l >= ql && r <= qr)
		return tree[p];
		
	return max(query(left(p), l, (l+r)>>1, ql, qr), query(right(p), ((l+r)>>1)+1, r, ql, qr));
}
