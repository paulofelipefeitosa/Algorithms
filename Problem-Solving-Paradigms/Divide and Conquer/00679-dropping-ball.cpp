#include <bits/stdc++.h>
using namespace std;
int d;
int func(int node, int i, int cont);
int main()
{
	int t;
	int i;
	while(scanf("%d", &t), t > -1)
	{
		while(t--)
		{
			scanf("%d %d", &d, &i);
			printf("%d\n", func(1, i, 1));
		}
	}
	return 0;
}
int func(int node, int i, int cont)
{
	if(cont == d)
		return node;
	int dir = i % 2;
	if(dir == 1)
		return func(node<<1, (i+1)>>1, cont+1);
	else
		return func(node<<1|1, (i+1)>>1, cont+1);
}
