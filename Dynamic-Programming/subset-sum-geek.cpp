#include <bits/stdc++.h>
using namespace std;
bool dp[50005];
bool ssp(int arr[], int n, int sum);
int main()
{
    int t;
    int arr[25];
    scanf("%d", &t);
    while(t--)
    {
        int n, sum;
      	scanf("%d %d", &sum, &n);
      	for(int i = 0;i < n;i++)
			scanf("%d", &arr[i]);
  		if(ssp(arr, n, sum))
			puts("YES");
		else
			puts("NO");
    }
    return 0;
}
/*bool ssp(int arr[], int n, int sum)
{
	for(int i = 1;i <= sum;i++)
		dp[i][0] = false;
	
	for(int i = 0;i <= n;i++)
		dp[0][i] = true;
	
	for(int i = 1;i <= sum;i++)
		for(int j = 1;j <= n;j++)
		{
			dp[i][j] = dp[i][j-1];
			if(i >= arr[j-1])
				dp[i][j] = dp[i][j] || dp[i - arr[j-1]][j-1];
		}
	
	return dp[sum][n];
}*/
bool ssp(int arr[], int n, int sum)//Only O(sum) memory space
{
	bool dp[sum+1];
    for(int i = 1;i <= sum;i++)
        dp[i] = false;
    dp[0] = true;
	for(int i = 0;i < n;i++)//a precedência dos for's influencia na construção da solução, os n veio primeiro pq ele nao pode ser usado varias vezes
		for(int j = sum;j >= arr[i];j--)//começar de trás pra frente tbm influencia
			dp[j] |= dp[j-arr[i]];
    return dp[sum];
}
