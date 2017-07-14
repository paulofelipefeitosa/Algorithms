#include <bits/stdc++.h>
using namespace std;
int n;
char bit[20];
void backtrack(int zr, int on, int cont);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int h;
		scanf("%d %d", &n, &h);
		backtrack(n-h, h, 0);
		if(t)
			putchar('\n');
	}
	return 0;
}
void backtrack(int zr, int on, int cont)
{
	if(cont == n)
	{
		bit[cont] = '\0';
		printf("%s\n", bit);
		return;
	}
	if(zr)
	{
		bit[cont] = '0';
		backtrack(zr-1, on, cont+1);
	}
	if(on)
	{
		bit[cont]= '1';
		backtrack(zr, on-1, cont+1);
	}
}

