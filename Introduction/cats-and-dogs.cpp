#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int c, d, l;
		scanf("%d %d %d", &c, &d, &l);
		int totpernas = (d<<2) + (c<<2);
		int pgato = l - (d<<2);
		int catdog = (d<<2) + (c<<2) - l;
		if((l % 4 == 0) && (l >= (d<<2)) && (l <= totpernas) && (pgato % 4 == 0) && ((pgato>>2) <= c) && (catdog % 4 == 0) && ((catdog>>2) <= (d<<1)))
			puts("yes");
		else
			puts("no");
	}
	return 0;
}