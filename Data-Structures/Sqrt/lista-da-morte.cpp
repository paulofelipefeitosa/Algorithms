#include <bits/stdc++.h>
#define MAX  100005
#define MAXS 605
using namespace std;
int li[MAX], n, s;
map<int, int>ami;
vector<int>group[MAXS];
void build();
int query(int a, int b);
int main()
{
	scanf("%d", &n);
	s = sqrt(n);
	if(s*s < n)
		s++;
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &li[i]);
		int gp = i/s;
		ami[li[i]] = gp;
		group[gp].push_back(li[i]);
	}
	int q;
	char op[2];
	scanf("%d", &q);
	while(q--)
	{
		scanf("%s", op);
		if(op[0] == 'I')
		{
			int p, e;
			scanf("%d %d", &p, &e);
			int gp = ami[e];
			ami[p] = gp;
			auto it = find(group[gp].begin(), group[gp].end(), e);
			group[gp].insert(++it, p);
			
			if(group[gp].size() >= (s<<1))
				build();
		}
		else if(op[0] == 'R')
		{
			int e;
			scanf("%d", &e);
			int gp = ami[e];
			auto it = find(group[gp].begin(), group[gp].end(), e);
			group[gp].erase(it);
		}
		else
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d\n", query(a, b));
		}
	}
	return 0;
}
int query(int a, int b)
{
	int gp1 = ami[a], gp2 = ami[b];
	if(gp1 > gp2)
	{
		swap(gp1, gp2);
		swap(a, b);
	}
	
	int p1 = find(group[gp1].begin(), group[gp1].end(), a) - group[gp1].begin();
	int p2 = find(group[gp2].begin(), group[gp2].end(), b) - group[gp2].begin();
	if(gp1 == gp2)
		return abs(p2 - p1) - 1;
	else
	{
		int cont = group[gp1].size() - p1 - 1 + p2;
		for(int i = gp1+1;i < gp2;i++)
			cont += group[i].size();
		return cont;
	}
}
void build()
{
	int k = 0;
	for(int i = 0;i < s;i++)
	{
		for(int j = 0;j < group[i].size();j++)
			li[k++] = group[i][j];
		group[i].clear();
	}
	s = sqrt(k);
	if(s*s < k)
		s++;
	for(int i = 0;i < k;i++)
	{
		group[i/s].push_back(li[i]);
		ami[li[i]] = i/s;
	}
}
