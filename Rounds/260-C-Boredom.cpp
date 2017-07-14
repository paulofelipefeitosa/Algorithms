#include <bits/stdc++.h>
#define MAX 100005
#define ll long long int
using namespace std;
ll occ[MAX] = {}, dp[MAX];
ll solve(int n);
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		int num;
		scanf("%d", &num);
		occ[num]++;
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = occ[1];
	dp[2] = occ[2]<<1;
	cout<<max(solve(100000), solve(99999))<<endl;
	return 0;
}
ll solve(int n)
{
	if(dp[n] != -1)
		return dp[n];
	return dp[n] = occ[n]*n + max(solve(n-2), solve(n-3));
}
