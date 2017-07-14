#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int alpha[20], beta[20];
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, x;
		scanf("%d %d", &n, &x);
		//printf("%d %d\n", n, x);
		for(int i = 0;i <= n;i++)
			cin>>alpha[i];
		beta[n-1] = alpha[n];
		for(int i = n-2;i >= 0;i--)
			beta[i] = alpha[i+1] + (beta[i+1]*x);
		long long int r = alpha[0] + (beta[0]*x);
		cout<<r<<endl;
		for(int i = 0;i < n;i++)
			cout<<beta[i]<<" ";
		cout<<endl;
	}
	return 0;
}
