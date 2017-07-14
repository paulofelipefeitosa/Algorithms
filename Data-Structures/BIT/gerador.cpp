#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 250, m = 250;
	printf("%d %d\n", n, m);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
			printf("1 ");
		putchar('\n');
	}
	printf("1 1\n");
	return 0;
}
