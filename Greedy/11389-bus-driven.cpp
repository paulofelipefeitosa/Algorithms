#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int main()
{
	int n, d, r;
	int mor[MAX], after[MAX];
	while(scanf("%d %d %d", &n, &d, &r), (n || d || r))
	{
		int imba = 0;
		for(int i = 0;i < n;i++)
			scanf("%d", &mor[i]);
		for(int i = 0;i < n;i++)
			scanf("%d", &after[i]);
		sort(mor, mor+n);
		sort(after, after+n);
		for(int i = 0;i < n;i++)
			imba += max(0, (mor[i] + after[n-1-i] - d));
		printf("%d\n", imba*r);
	}
	return 0;
}
