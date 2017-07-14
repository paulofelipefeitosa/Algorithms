#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
map<pair<int,int>, bool>mapa;
int pai[MAX<<2], peso[MAX<<2];
int aa[MAX<<2], bb[MAX<<2];
void join(int a, int b);
int ffind(int x);
int v;
int main()
{
	srand(time(NULL));
	int n = MAX;
	int cont = 0;
	for(int i = 1;i <= n;i++)
		pai[i] = i, peso[i] = 1;
	v = n;
	while(v > 1)
	{
		int v1 = rand()%n + 1;
		int v2 = rand()%n + 1;
		if(v1 != v2 && mapa.find(make_pair(v1, v2)) == mapa.end())
		{
			aa[cont] = v1;
			bb[cont++] = v2;
			if(ffind(v1) != ffind(v2))
			{
				mapa[make_pair(v1, v2)] = true;
				join(v1, v2);
			}
		}
	}
	printf("%d %d\n", n, cont);
	while(cont--)
		printf("%d %d\n", aa[cont], bb[cont]);
	return 0;
}
void join(int a, int b)
{
	a = ffind(a); b = ffind(b);
	if(a == b)
		return;
	if(peso[a] > peso[b])
		pai[b] = a;
	else if(peso[a] < peso[b])
		pai[a] = b;
	else
	{
		pai[a] = b;
		peso[b]++;
	}
	v--;
}
int ffind(int x)
{
	if(pai[x] == x)
		return x;
	else
		return pai[x] = ffind(pai[x]);
}
