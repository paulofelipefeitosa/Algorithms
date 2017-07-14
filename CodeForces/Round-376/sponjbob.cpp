#include <bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
int main()
{
	ulli x, m, n = 1;
	set<pair<ulli,ulli> >ans;
	cin>>x;
	do
	{
		ulli a = ((n*n)+n)>>1;
		ulli b = (((((n-1)*(n-1))+(n-1))>>1)*n) - (((n-1)*n*((n<<1)-1))/6);
		if((x+b) % a == 0)
			m = ((x+b)/a);
		else
		{
			m = ((x+b)/a);
			if(m < n)
				break;
			n++;
			continue;
		}
		if(m < n)
			break;
		ans.insert(pair<ulli, ulli>(n, m));
		ans.insert(pair<ulli, ulli>(m, n));
		n++;
	}while(1);
	cout<<ans.size()<<endl;
	for(auto it = ans.begin();it != ans.end();it++)
		cout<<(*it).first<<" "<<(*it).second<<endl;
	return 0;
}
