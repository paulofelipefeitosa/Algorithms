#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, l, r, x;
	scanf("%d %d %d %d", &n, &l, &r, &x);
	int dif[n];
	for(int i = 0;i < n;i++)
		scanf("%d", &dif[i]);
	int ans = 0;
	for(int j = 0;j < (1<<n);j++)
	{
		int sum = 0, qt = 0, mn = INT_MAX, mx = INT_MIN;
		for(int k = 0;k < n;k++)
			if((j >> k) & 1)
			{
				sum += dif[k];
				qt++;
				mn = min(mn, dif[k]);
				mx = max(mx, dif[k]);
			}
		if(qt > 1 && sum >= l && sum <= r && (mx - mn) >= x)
			ans++;
	}
	printf("%d\n", ans );
	return 0;
}
