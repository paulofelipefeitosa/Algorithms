#include <bits/stdc++.h>
#define MAX 25
using namespace std;
char ver[MAX], path[MAX];
bool depends[150][150] = {};
int tam1, tam2, used, v;
void backtrack(int ori);
bool check(int cont, char vert);
int main()
{
	char end = 0;
	char str_ver[MAX<<1], str_lig[MAX<<3];
	while(scanf("%[^\n]s", str_ver)!=EOF)
	{
		if(end)
			putchar('\n');
		
		getchar();
		scanf("%[^\n]s", str_lig);
		getchar();
		
		tam1 = strlen(str_ver);
		tam2 = strlen(str_lig);
		v = (tam1+1)>>1;
		
		for(int i=0, j=0;i<tam1;i+=2, j++)
			ver[j] = str_ver[i];
		ver[v] = '\0';
		sort(ver, ver+v);
		
		for(int i=0;i<tam2;i+=4)
			depends[str_lig[i+2]][str_lig[i]] = true;
			
		used = 0;
		backtrack(0);
		
		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				depends[ver[i]][ver[j]] = false;
		end = 1;
	}
	return 0;
}
void backtrack(int cont)
{
	if(cont == v)
	{
		path[v] = '\0';
		printf("%s\n", path);
		return;
	}
	for(int i=0;i<v;i++)
	{
		if(!(used & (1<<i)) && check(cont, ver[i]))
		{
			used |= (1<<i);
			path[cont] = ver[i];
			backtrack(cont+1);
			used &= ~(1<<i);
		}
	}
}
bool check(int cont, char vert)
{
	for(int i=0;i<cont;i++)
		if(depends[path[i]][vert])
			return false;
	return true;
}
