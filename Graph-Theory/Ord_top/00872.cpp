#include <bits/stdc++.h>
#define MAX 25
using namespace std;
char dep[260][260] = {}, path[MAX], ord[MAX];
int tam, used;
void backtrack(int cont);
bool can_put(int i, int cont);
bool flag;
int main()
{
	char str[MAX<<1], chs[4], c;
	int t;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		getchar();
		scanf("%[^\n]s", str);
		getchar();
		tam = strlen(str);
		for(int i=0;i<tam;i+=2)
			ord[i>>1] = str[i];
		tam = (tam+1)>>1;
		sort(ord, ord+tam);
		do
		{
			scanf("%s", chs);
			dep[chs[2]][chs[0]] = 1;
			c = getchar();
		}while(c == ' ');
		used = 0;
		flag = false;
		backtrack(0);
		if(!flag)
			puts("NO");
		for(int i=0;i<tam;i++)
			for(int j=0;j<tam;j++)
				dep[ord[i]][ord[j]] = 0;
		if(t)
			putchar('\n');
	}
	return 0;
}
void backtrack(int cont)
{
	if(cont == tam)
	{
		putchar(path[0]);
		for(int i = 1;i < tam;i++)
			printf(" %c", path[i]);
		putchar('\n');
		flag = true;
		return;
	}
	for(int i = 0;i < tam;i++)
	{
		if(!(used & (1<<i)) && can_put(i, cont))
		{
			used |= (1<<i);
			path[cont] = ord[i];
			backtrack(cont+1);
			used &= ~(1<<i);
		}
	}
}
bool can_put(int i, int cont)
{
	for(int j = 0;j < cont;j++)
		if(dep[path[j]][ord[i]])
			return false;
	return true;
}
