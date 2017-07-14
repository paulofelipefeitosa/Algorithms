#include <bits/stdc++.h>
using namespace std;
char word[105][260];
char rule[260];
int n, tam, ans[260];
void backtrack(int cont);
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0;i < n;i++)
			scanf("%s", word[i]);
		int m;
		scanf("%d", &m);
		printf("--\n");
		for(int i = 0;i < m;i++)
		{
			scanf("%s", rule);
			tam = strlen(rule);
			backtrack(0);
		}
	}
	return 0;
}
void backtrack(int cont)
{
	if(cont == tam)
	{
		for(int i = 0;i < tam;i++)
			if(rule[i] == '0')
				printf("%d", ans[i]);
			else
				printf("%s", word[ans[i]]);
		putchar('\n');
	}
	else
	{
		int k;
		if(rule[cont] == '0')
			k = 10;
		else
			k = n;
		for(int j = 0;j < k;j++)
		{
			ans[cont] = j;
			backtrack(cont+1);
		}
	}
}

