#include <bits/stdc++.h>

#define rep(i, j) for(i = 0;i < j;i++)
typedef pair<int,int> pi
typedef vector<int> vi

using namespace std;

const int MX = 131072;
int n, N, dat[(MX<<1)-1];
pi p[100000], q[100000];

int query(int a,int b,int k,int l,int r)
void update(int k,int a);

int main()
{
	cin>>n;
	rep(i, n)
	{
		cin>>p[i].first>>p[i].second;
		q[i] = p[i];
		q[i].second = i;
	}
	
	sort(p, p+n);
	sort(q, q+n);
	
	N = 1;
	while(N < n)
		N<<=1;
	
	rep(i, (N<<1)-1)
		dat[i] = 0;
	
	vi ans(n);
	
	for(int i = n-1;i >= 0;i--)
	{
		int mx = lower_bound(p, p+n, pi(p[i].first+p[i].second, 0)) - p;
		mx = max(mx, query(i+1, mx, 0, 0, N));
		update(i, mx);
		ans[q[i].second] = mx - i;
	}
	
	rep(i, n)
		cout<<ans[i]<<" ";
		
	cout<<endl;
	
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

