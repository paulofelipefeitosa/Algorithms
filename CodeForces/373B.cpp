#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
ll log_10(ll i);
ll fexp(ll b, int e);
ll bfind(ll r, ll aux, ll w);
int main()
{
	ll w, m, k, aux, ans = 0;
	ll qnt, req, dig;
	cin>>w>>m>>k;
	while(w)
	{
		dig = log_10(m);
		aux = fexp(10, dig);
		req = aux - m;
		m = aux;
		aux = dig*k;
		qnt = bfind(req, aux, w);
		//cout<<qnt<<endl;
		if(qnt == 0)
			w = 0;
		else
		{
			w -= qnt*aux;
			ans += qnt;
		}
	}
	cout<<ans<<endl;
	return 0;
}
ll bfind(ll r, ll aux, ll w)
{
	ll l = 1, mid, ans = 0;
	while(l <= r)
	{
		mid = (l+r)/2;
		//cout<<l<<" "<<mid<<" "<<r<<endl;
		if(mid*aux <= w)
		{
			ans = max(ans, mid);
			l = mid+1;
		}
		else
			r = mid-1;
	}
	return ans;
}
ll fexp(ll b, int e)
{
	if(e == 0)	return 1;
	ll x = fexp(b, e>>1);
	if(e & 1)	return x*x*b;	
	else		return x*x;
}
ll log_10(ll i)
{
	ll cont = 0;
	do
	{
		cont++;
		i /= 10;
	}while(i);
	return cont;
}
