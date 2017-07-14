#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	printf("10000\n");
	for(int i = 0;i < 10000;i++)
		printf("%d ", i+1);
	putchar('\n');
	printf("100000\n");
	int l;
	for(int i = 0;i < 100000;i++)
	{
		l = (rand()%10000)+1;
		printf("%d %d %d\n", l, min(10000, l+10000), (rand()%1000000000) + 1);
	}
	return 0;
}
