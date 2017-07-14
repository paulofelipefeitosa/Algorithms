#include <bits/stdc++.h>
using namespace std;
int n, ca, cb, ans[10000];
bool marq[1000][1000] = {};
bool backtrack(int a, int b, int cont);
int main()
{
	while(scanf("%d %d %d", &ca, &cb, &n) != EOF)
	{
		backtrack(0, 0, 0);
	}
	return 0;
}
bool backtrack(int a, int b, int cont)
{
	if(b == n)
	{
		for(int i = 0;i < cont;i++)
		{
			if(ans[i] == 0)
				puts("fill A");
			else if(ans[i] == 1)
				puts("fill B");
			else if(ans[i] == 2)
				puts("empty A");
			else if(ans[i] == 3)
				puts("empty B");
			else if(ans[i] == 4)
				puts("pour A B");
			else
				puts("pour B A");
		}
		puts("success");
		return true;
	}
	if(a < ca && !marq[ca][b])
	{
		ans[cont] = 0;
		marq[ca][b] = true;
		if(backtrack(ca, b, cont+1))
		{
			marq[ca][b] = false;
			return true;
		}
		marq[ca][b] = false;
	}
	if(b < cb && !marq[a][cb])
	{
		ans[cont] = 1;
		marq[a][cb] = true;
		if(backtrack(a, cb, cont+1))
		{
			marq[a][cb] = false;
			return true;
		}
		marq[a][cb] = false;
	}
	if(a && !marq[0][b])
	{
		ans[cont] = 2;
		marq[0][b] = true;
		if(backtrack(0, b, cont+1))
		{
			marq[0][b] = false;
			return true;
		}
		marq[0][b] = false;
	}
	if(b && !marq[a][0])
	{
		ans[cont] = 3;
		marq[a][0] = true;
		if(backtrack(a, 0, cont+1))
		{
			marq[a][0] = false;
			return true;
		}
		marq[a][0] = false;
	}
	int sa = max(0, a - (min(b+a, cb) - b));
	int sb = min(b+a, cb);
	if(!marq[sa][sb])
	{
		ans[cont] = 4;
		marq[sa][sb] = true;
		if(backtrack(sa, sb, cont+1))
		{
			marq[sa][sb] = false;
			return true;
		}
		marq[sa][sb] = false;
	}
	sa = min(a+b, ca);
	sb = max(0, b - (min(a+b, ca) - a));
	if(!marq[sa][sb])
	{
		ans[cont] = 5;
		marq[sa][sb] = true;
		if(backtrack(sa, sb, cont+1))
		{
			marq[sa][sb] = false;
			return true;
		}
		marq[sa][sb] = false;
	}
	return false;
}
