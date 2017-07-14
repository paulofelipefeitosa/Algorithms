#include <bits/stdc++.h>
using namespace std;
int m, n, qt, ans[70000];
bool used[70000] = {};
int fexp(int b, int e);
bool backtrack(int cont, int ant);
int main()
{
	while(scanf("%d %d", &m, &n) != EOF)
	{
		qt = fexp(n, m);
		for(int i = 0;i < m;i++)
			ans[i] = 0;
		used[0] = true;
		backtrack(m, 0);
	}
	return 0;
}
bool backtrack(int cont, int ant)
{
	if(cont == qt)
	{
		int kept[m], pt = 0;
		for(int i = qt-m+1;i < qt;i++)
		{
			int aux = ant - (fexp(n, m-1)*ans[i-1]);
			int hash = (n*aux) + ans[(i+m)%qt];
			if(used[hash])
			{
				for(int j = 0;j < pt;j++)
					used[kept[j]] = false;
				return false;
			}
			used[hash] = true;
			kept[pt++] = hash;
			ant = hash;
		}
		for(int j = 0;j < pt;j++)
			used[kept[j]] = false;
		for(int i = 0;i < qt;i++)
			printf("%d", ans[i]);
		putchar('\n');
		return true;
	}
	int aux = ant - (fexp(n, m-1)*ans[cont-m]);
	for(int dig = 0;dig < n;dig++)
	{
		int hash = (n*aux) + dig;
		if(!used[hash])
		{
			used[hash] = true;
			ans[cont] = dig;
			if(backtrack(cont+1, hash))
			{
				used[hash] = false;
				return true;
			}
			used[hash] = false;
		}
	}
	return false;
}
int fexp(int b, int e)
{
	if(e == 0)	return 1;
	int x = fexp(b, e>>1);
	if(e & 1)	return b*x*x;
	else		return x*x;
}
