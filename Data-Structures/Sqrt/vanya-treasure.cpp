#include <bits/stdc++.h>
#define MAX 305
using namespace std;
int dp[MAX][MAX], grid[MAX][MAX];
int cont[MAX*MAX] = {};
vector<pair<int,int> >pos[MAX*MAX];
int main()
{
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
		{
			scanf("%d", &grid[i][j]);
			pos[grid[i][j]].push_back(make_pair(i, j));
			cont[grid[i][j]]++;
			
			if(grid[i][j] == 1)
				dp[i][j] = i + j;
			else
				dp[i][j] = 1<<30;
		}
	for(int color = 2;color <= p;color++)
	{
		if(cont[color] * cont[color - 1] < (n * m))
		{
			for(pair<int,int> c1 : pos[color])
				for(pair<int,int> c2 : pos[color - 1])
					dp[c1.first][c1.second] = min(dp[c1.first][c1.second], dp[c2.first][c2.second] 
																			+ abs(c1.first - c2.first) + abs(c1.second - c2.second));
		}
		else
		{
			
		}
	}
	printf("%d\n", dp[pos[p][0].first][pos[p][0].second]);
	return 0;
}
