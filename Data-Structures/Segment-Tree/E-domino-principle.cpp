#include <bits/stdc++.h>

#define rep(i, l, r) for(int i = l;i < r;i++)
#define repi(i, l, r) for(int i = l;i <= r;i++)

#define pi pair<int,int>
#define vi vector<int>
#define pb push_back

#define fi first
#define se second

#define geti(a) scanf("%d", &a)
#define getii(a, b) scanf("%d %d", &a, &b)
#define sc(c) putchar(c)

#define lli long long int
#define ulli unsigned long long int

#define INFi 1<<30
#define INFli 100100100100100100

#define CLS(x, a) memset(x, a, sizeof x)

#define IOS ios_base::sync_with_stdio(0)

using namespace std;

const int MX = 131072;
int n, N, dat[(MX<<1)-1];
pi p[100000], q[100000];
int 

int query(int a, int b, int k, int l, int r);
void update(int k, int a);

int main()
{
	geti(n);
	rep(i, 0, n)
	{
		getii(p[i].fi, p[i].se);
		q[i] = p[i];
		q[i].se = i;
	}
	
	sort(p, p+n);
	sort(q, q+n);
	
	N = 1;
	while(N < n)
		N<<=1;
	
	rep(i, 0, (N<<1)-1)
		dat[i] = 0;
	
	vi ans(n);
	
	for(int i = n-1;i >= 0;i--)
	{
		int mx = lower_bound(p, p+n, pi(p[i].fi + p[i].se, 0)) - p;
		mx = max(mx, query(i+1, mx, 0, 0, N));
		update(i, mx);
		ans[q[i].second] = mx - i;
	}
	
	rep(i, 0, n)
		printf("%d ", ans[i]);
		
	sc('\n');
	
	return 0;
}

int query(int a, int b, int k, int l, int r)
{
	if(r <= a || b <= l)
		return 0;
	if(a <= l && r <= b)
		return dat[k];
	return max(query(a, b, k<<1|1, l, (l+r)>>1),query(a, b, (k<<1)+2, (l+r)>>1, r));
}

void update(int k, int a)
{
	k += N-1;
	dat[k] = a;
	while(k > 0)
	{
		k = (k-1)>>1;
		dat[k] = max(dat[k<<1|1], dat[(k<<1)+2]);
	}
}

