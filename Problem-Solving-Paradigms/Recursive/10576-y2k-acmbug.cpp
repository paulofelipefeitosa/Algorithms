#include <bits/stdc++.h>
using namespace std;
int ans[12], s, d, mx;
void backtrack(int y);
int main()
{
	while(scanf("%d %d", &s, &d) != EOF)
	{
		mx = -1010101010;
		backtrack(0);
		if(mx < 0)
			puts("Deficit");
		else
			printf("%d\n", mx);
	}
	return 0;
}
void backtrack(int y)
{
	if(y == 12)
	{
		int sum = 0;
		for(int i = 0;i < 5;i++)
			sum += ans[i];
		if(sum >= 0)
			return;
		for(int i = 5;i < 12;i++)
		{
			sum -= ans[i-5];
			sum += ans[i];
			if(sum >= 0)
				return;
		}
		sum = 0;
		for(int i = 0;i < 12;i++)
			sum += ans[i];
		mx = max(mx, sum);
	}
	else
	{
		ans[y] = s;
		backtrack(y+1);
		ans[y] = -d;
		backtrack(y+1);
	}
}
