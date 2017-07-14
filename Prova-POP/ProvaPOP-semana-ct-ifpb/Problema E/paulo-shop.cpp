#include <bits/stdc++.h>
using namespace std;
int n;
int qnt[3], people[3] = {}, val[3];
bool comp(int a, int b);
int main()
{	
	string cor;
	scanf("%d", &n);
	scanf("%d %d %d", &qnt[0], &qnt[1], &qnt[2]);
	scanf("%d %d %d", &val[0], &val[1], &val[2]);
	for(int i = 0;i < n;i++)
	{
		cin >> cor;
		if(cor == "azul")
			people[0]++;
		else if(cor == "amarela")
			people[1]++;
		else
			people[2]++;
	}
	
	double money = 0;
	money += val[0]*min(qnt[0], people[0]);
	money += val[1]*min(qnt[1], people[1]);
	money += val[2]*min(qnt[2], people[2]);
	
	int resto = 0;
	resto += people[0] - min(qnt[0], people[0]);
	resto += people[1] - min(qnt[1], people[1]);
	resto += people[2] - min(qnt[2], people[2]);
	
	qnt[0] -= min(qnt[0], people[0]);
	qnt[1] -= min(qnt[1], people[1]);
	qnt[2] -= min(qnt[2], people[2]);
	
	int p[3];
	for(int i = 0;i < 3;i++)
		p[i] = i;
	sort(p, p+3, comp);
	
	for(int i = 0;i < 3;i++)
	{
		money += (val[p[i]]/2.00)*min(resto, qnt[p[i]]);
		resto -= min(resto, qnt[p[i]]);
	}
	
	printf("%.2f\n", money);
	return 0;
}
bool comp(int a, int b)
{
	return val[a] > val[b];
}
