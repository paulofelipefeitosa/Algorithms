#include <bits/stdc++.h>
using namespace std;
struct vert
{
	vector<int>conf;
	int w;
};
struct comp
{
	bool operator()(vert a, vert b)
	{
		return a.w > b.w;
	}
};
int dijkstra(vector<int>ori, vector<int>des);
int main()
{
	vector<int>mori(8), mdes(8);
	
	for(int i = 0;i < 8;i++)
		scanf("%d", &mori[i]);
	for(int i = 0;i < 8;i++)
		scanf("%d", &mdes[i]);
		
	printf("%d\n", dijkstra(mori, mdes));
	return 0;
}
int dijkstra(vector<int>ori, vector<int>des)
{
	priority_queue<vert, vector<vert>, comp>fila;
	map<vector<int>, int>custo;
	vector<int>u;
	int ww, val;
	
	custo[ori] = 0;
	fila.push((vert){ori, custo[ori]});
	
	if(ori == des)
		return 0;
		
	while(!fila.empty())
	{
		u = fila.top().conf;
		ww = fila.top().w;
		fila.pop();
		if(custo[u] == ww)
		{
			for(int i = 0, k = 4;i < 4;i++, k++)
			{
				val = u[i] + u[k];
				swap(u[i], u[k]);
				if(custo.find(u) == custo.end())
				{
					custo[u] = ww + val;
					fila.push((vert){u, custo[u]});
				}
				else if(ww + val < custo[u])
				{
					custo[u] = ww + val;
					fila.push((vert){u, custo[u]});
				}
				swap(u[i], u[k]);
			}
			for(int i = 1;i < 4;i++)
			{
				val = u[i-1] + u[i];
				swap(u[i-1], u[i]);
				if(custo.find(u) == custo.end())
				{
					custo[u] = ww + val;
					fila.push((vert){u, custo[u]});
				}
				else if(ww + val < custo[u])
				{
					custo[u] = ww + val;
					fila.push((vert){u, custo[u]});
				}
				swap(u[i-1], u[i]);
			}
			for(int i = 5;i < 8;i++)
			{
				val = u[i-1] + u[i];
				swap(u[i-1], u[i]);
				if(custo.find(u) == custo.end())
				{
					custo[u] = ww + val;
					fila.push((vert){u, custo[u]});
				}
				else if(ww + val < custo[u])
				{
					custo[u] = ww + val;
					fila.push((vert){u, custo[u]});
				}
				swap(u[i-1], u[i]);
			}
		}
	}
	return custo[des];
}
