#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
int c[11], t;
double func(double irr);
double fastexp(double b, int e);
int main()
{
	while(scanf("%d", &t), t)//the function is stricly decreasing, and don't have any critical point in your derivative
	{						//Because your coeficients are all positive to all CFi and i > 0.
		for(int i = 0;i <= t;i++)
			scanf("%d", &c[i]);
		double l = -1, r = 1000000000000, mid;
		int itr = 0;
		while(r - l > EPS && itr < 300)
		{
			mid = (l+r)/2;
			if(func(mid) > 0)
				l = mid;
			else
				r = mid;
			itr++;
		}
		printf("%.2lf\n", mid);
	}
	return 0;
}
double func(double irr)
{
	double ans = 0;
	for(int i = 0;i <= t;i++)
		ans += c[i]/fastexp(1+irr, i);
	return ans;
}
double fastexp(double b, int e)
{
	if(e == 0)
		return 1;
	double x = fastexp(b, e>>1);
	if(e & 1)
		return b*x*x;
	else
		return x*x;
}
