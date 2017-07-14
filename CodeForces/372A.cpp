#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, kang[500005];
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", &kang[i]);
	sort(kang, kang+n);
	int qnt = n;
	int mid = (n-1)>>1, l = mid, r = n-1;
	while(l >= 0 && r > mid)
	{
		if((kang[l]<<1) <= kang[r])
		{
			qnt--;
			r--;
		}
		l--;
	}
	printf("%d\n", qnt);
	return 0;
}
