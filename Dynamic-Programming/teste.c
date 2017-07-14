#include <bits/stdc++.h>
using namespace std;
bool dp[1005];
int ssp(int arr[], int n, int k);
int main()
{
    int t;
    int arr[105];
    scanf("%d", &t);
    while(t--)
    {
        int n, sum = 0, i;
      	scanf("%d", &n);
      	for(i = 0;i < n;i++)
      	{
      		scanf("%d", &arr[i]);
      		sum+=arr[i];
      	}
      	if(sum & 1)
      		puts("NO");
      	else
      	{
      		if(ssp(arr, n, sum>>1))
				puts("YES");
			else
				puts("NO");
      	}
    }
    return 0;
}
int ssp(int arr[], int n, int k)
{
    for(int i = 1;i <= k;i++)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 0;i < n;i++)
        for(int j = k;j >= arr[i];j--)
            dp[j] |= dp[j-arr[i]];
    return dp[k];
}
