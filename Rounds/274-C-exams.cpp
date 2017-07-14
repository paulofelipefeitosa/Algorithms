#include <bits/stdc++.h>
#define MAX 5005
using namespace std;
pair<int,int>ab[MAX];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d %d", &ab[i].first, &ab[i].second);
	sort(ab, ab+n);
	int ans = 0;
	for(int i = 0;i < n;i++)
		if(ab[i].second >= ans)
			ans = ab[i].second;
		else
			ans = ab[i].first;
	printf("%d\n", ans);
	return 0;
}
