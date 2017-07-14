#include <bits/stdc++.h>
#define MAX 260
using namespace std;

bool dep[MAX][MAX] = {};
char secret_key[MAX], chars[MAX];
int pt, used;

void backtrack(int cont);
bool can(int cont, int j);

int main()
{
	int n;
	char triplet[5];
	set<char>myset;
	
	scanf("%d", &n);//quantidade de triplets
	getchar();
	
	for(int i = 0;i < n;i++)
	{
		scanf("%s", triplet);
		getchar();
		
		for(int j = 0;j < 3;j++)
		{
			myset.insert(triplet[j]);
			for(int k = j+1;k < 3;k++)
				dep[triplet[k]][triplet[j]] = true;
		}
	}
	
	pt = 0;
	for(set<char>::iterator it = myset.begin();it != myset.end();it++)
		chars[pt++] = *it;
		
	used = 0;
	backtrack(0);
	
	for(int i = 0;i < pt;i++)
		for(int j = 0;j < pt;j++)
			dep[chars[i]][chars[j]] = false;
			
	return 0;
}
void backtrack(int cont)
{
	if(cont == pt)
	{
		secret_key[cont] = '\0';
		printf("%s\n", secret_key);
		return;
	}
	
	for(int i = 0;i < pt;i++)
		if(!(used & (1<<i)) && can(cont, i))
		{
			used |= (1<<i);
			secret_key[cont] = chars[i];
			
			backtrack(cont+1);
			
			used &= ~(1<<i);
		}
}
bool can(int cont, int j)
{
	for(int i = 0;i < cont;i++)
		if(dep[secret_key[i]][chars[j]])
			return false;
	return true;
}
