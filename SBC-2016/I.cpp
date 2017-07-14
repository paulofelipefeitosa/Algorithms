#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, alt[50005];
	int esq[50005], dir[50005];
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", &alt[i]);
	esq[0] = 1;
	for(int i = 1;i < n;i++)
		esq[i] = min(esq[i-1]+1, alt[i]);
	dir[n-1] = 1;
	for(int i = n-2;i >= 0;i--)
		dir[i] = min(dir[i+1]+1, alt[i]);
	int ans = 0;
	for(int i = 0;i < n;i++)
		ans = max(ans, min(esq[i], dir[i]));
	printf("%d\n", ans);
	return 0;
}
