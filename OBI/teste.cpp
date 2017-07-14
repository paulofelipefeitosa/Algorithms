#include <bits/stdc++.h>
#define MAX 2005
using namespace std;
char str[MAX];
int memo[MAX][MAX];
bool pal[MAX][MAX] = {};
bool ispal(int i, int j);
int solve(int i, int j);
int main()
{
	int n, cont = 1;
	while(scanf("%d", &n), n)
	{
		scanf("%s", str);
		for(int i = 0;i < n;i++)
		{
			pal[i][i] = true;
			memo[i][i] = 0;
		}
		for(int l = 2;l <= n;l++)
			for(int i = 0;i < n - l + 1;i++)
			{
				int j = i + l - 1;
				if(l == 2)
					pal[i][j] = (str[i] == str[j]);
				else
					pal[i][j] = (str[i] == str[j]) && pal[i+1][j-1];
				if(pal[i][j])
					memo[i][j] = 0;
				else
					memo[i][j] = -1;
			}
		printf("Teste %d\n", cont++);
		printf("%d\n\n", solve(0, n-1)+1);
	}
	return 0;
}
int solve(int i, int j)
{
	if(pal[i][j])
		return 0;
	if(memo[i][j] != -1)
		return memo[i][j];
	int m = 1<<30;
	for(int k = i;k < j;k++)
		m = min(m, solve(i, k) + 1 + solve(k+1, j));
	return memo[i][j] = m;
}
bool ispal(int i, int j)
{
	for(int k = i, l = j;k <= j;k++, l--)
		if(str[k] != str[l])
			return false;
	return true;
}
