#include <bits/stdc++.h>
#define INF 1<<30
using namespace std;

map<vector<int>, int>indx;
vector<pair<int,int> >graph[41000];
bool marq[41000] = {};

int dijkstra(int ori, int des);
void build_adj(vector<int>&conf);
int main()
{
	vector<int>mori(8), mdes(8), cpy(8);
	
	for(int i = 0;i < 8;i++)
		scanf("%d", &mori[i]);
	for(int i = 0;i < 8;i++)
		scanf("%d", &mdes[i]);
	
	int cont = 1;	
	cpy = mori;
	sort(cpy.begin(), cpy.end());
	do
	{
		indx[cpy] = cont++;
	}while(next_permutation(cpy.begin(), cpy.end()));
	
	build_adj(mori);
		
	printf("%d\n", dijkstra(indx[mori], indx[mdes]));
	return 0;
}
void build_adj(vector<int>&conf)
{
	int u = indx[conf], val, v;
	marq[u] = true;
	for(int i = 0, k = 4;i < 4;i++, k++)
	{
		val = conf[i] + conf[k];
		swap(conf[i], conf[k]);
		v = indx[conf];
		graph[u].push_back(pair<int,int>(v, val));
		if(!marq[v])
			build_adj(conf);
		swap(conf[i], conf[k]);
	}
	for(int i = 1;i < 4;i++)
	{
		val = conf[i-1] + conf[i];
		swap(conf[i-1], conf[i]);
		v = indx[conf];
		graph[u].push_back(pair<int,int>(v, val));
		if(!marq[v])
			build_adj(conf);
		swap(conf[i-1], conf[i]);
	}
	for(int i = 5;i < 8;i++)
	{
		val = conf[i-1] + conf[i];
		swap(conf[i-1], conf[i]);
		v = indx[conf];
		graph[u].push_back(pair<int,int>(v, val));
		if(!marq[v])
			build_adj(conf);
		swap(conf[i-1], conf[i]);
	}
}
int dijkstra(int ori, int des)
{
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >fila;
	vector<int>custo(41000, INF);
	int u, v, w, ww;
	
	custo[ori] = 0;
	fila.push(pair<int,int>(custo[ori], ori));
		
	while(!fila.empty())
	{
		u = fila.top().second;
		w = fila.top().first;
		fila.pop();
		if(custo[u] == w)
		{
			for(int i = 0;i < 10;i++)
			{
				v = graph[u][i].first;
				ww = graph[u][i].second;
				if(w + ww < custo[v])
				{
					custo[v] = w + ww;
					fila.push(pair<int,int>(custo[v], v));
				}
			}
		}
	}
	return custo[des];
}
