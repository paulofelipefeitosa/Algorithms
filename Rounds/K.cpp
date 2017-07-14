#include <bits/stdc++.h>
using namespace std;
struct BOX
{
	int w, r;
};
BOX box[1005];
int memo[1005][2], n;
int dp(int i, int res, int st);
bool comp(BOX a, BOX b)
{
	return (a.r-a.w) > (b.r-b.w);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d", &box[i].w, &box[i].r);
			memo[i][0] = memo[i][1] = -1;
		}
		sort(box, box+n, comp);
		printf("%d\n", dp(0, 10000000, 0));
	}
	return 0;
}
int dp(int i, int res, int st)
{
	if(i == n || res == 0) 	return 0;
	if(memo[i][st] != -1) 	return memo[i][st];
	if(res < box[i].w) 		return memo[i][st] = dp(i+1, res, 0);
	return memo[i][st] = max(dp(i+1, res, 0), 1 + dp(i+1, min(res-box[i].w, box[i].r-box[i].w), 1));
}
