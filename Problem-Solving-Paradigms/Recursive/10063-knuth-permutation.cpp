#include <bits/stdc++.h>
using namespace std;
char str[15], sol[10][4038000][10];
int size[10] = {};
void backtrack(int i);
int main()
{
	backtrack(9);
	char ans[15];
	bool cont = false;
	while(scanf("%s", str) != EOF)
	{
		if(cont)
			putchar('\n');
		int tam = strlen(str) - 1;
		for(int i = 0;i < size[tam];i++)
		{
			for(int j = 0;j <= tam;j++)
				ans[j] = str[sol[tam][i][j]];
			ans[tam+1] = '\0';
			printf("%s\n", ans);
		}
		cont = true;
	}
	return 0;
}
void backtrack(int i)
{	
	if(i == 0)
	{
		sol[i][size[i]++][0] = i;
		return;
	}
	
	backtrack(i-1);
	
	for(int l = 0;l < size[i-1];l++)
		for(int j = 0;j <= i;j++)
		{
			for(int k = 0, pt = 0;k <= i;k++)
			{
				if(k == j)
					sol[i][size[i]][k] = i;
				else
					sol[i][size[i]][k] = sol[i-1][l][pt++];
			}
			size[i]++;
		}
}
