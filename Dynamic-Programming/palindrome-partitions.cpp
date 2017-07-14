#include <bits/stdc++.h>
#define MAX 2005
using namespace std;
char str[MAX];
int dp[MAX];
bool pal[MAX][MAX];
int main()
{
	int n, cont = 1;
	while(scanf("%d", &n), n)
	{
		scanf("%s", str);
		for(int i = 0;i < n;i++)
			pal[i][i] = true;
		for(int l = 2;l <= n;l++)
			for(int i = 0;i < n - l + 1;i++)
			{
				int j = i + l - 1;
				if(l == 2)
					pal[i][j] = (str[i] == str[j]);
				else
					pal[i][j] = (str[i] == str[j]) && pal[i+1][j-1];
			}
		for(int i = 0;i < n;i++)
		{
			if(pal[0][i] == true)
				dp[i] = 0;
			else
			{
				dp[i] = 1<<30;
				for(int j = 0;j < i;j++)
					if(pal[j+1][i] == true && dp[j] + 1 < dp[i])
						dp[i] = dp[j] + 1;
			}
		}
		printf("Teste %d\n", cont++);
		printf("%d\n\n", dp[n-1]+1);
	}
	return 0;
}
