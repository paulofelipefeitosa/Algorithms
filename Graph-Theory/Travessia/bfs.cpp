#include <bits/stdc++.h>
#define MAX_VERT 100005
using namespace std;

vector<int>lista_adj[MAX_VERT];
bool mark[MAX_VERT] = {};

bool BFS(int ori, int des);

int main()
{
	int qnt_vert, qnt_ares;
	cin>>qnt_vert>>qnt_ares;
	
	int v1, v2;
	for(int i = 0;i < qnt_ares;i++)
	{
		cin>>v1>>v2;
		lista_adj[v1].push_back(v2);
		lista_adj[v2].push_back(v1);
	}
	
	cin>>v1>>v2;					//consulta! existe um caminho do vertice v1 para o vertice v2 ?
	
	if(bfs(v1, v2) == true)			//EXISTE
		puts("YES!!!");
	else							//NAO EXISTE
		puts("NO!!!");
	
	for(int i = 0;i <= qnt_vert;i++)//limpar a lista de adjacência e o vetor de marcação para novos casos de teste
	{
		lista_adj[i].clear();
		mark[i] = false;
	}
	return 0;
}

bool BFS(int ori, int des)
{
	queue<int>fila;
	
	fila.push(ori);
	mark[ori] = true;
	
	while(!fila.empty())
	{
		int u = fila.front();
		
		fila.pop();
		
		for(int i = 0;i < lista[u].size();i++)
		{
			int v = lista[u][i];
			
			if(mark[v] == false)
			{
				mark[v] = true;
				fila.push(v);
				
				/*if(v == des)			//verifica logo aqui se v é o vertice que estou buscando
					return true;*/
			}
		}
	}
	if(mark[des] == true)
		return true;
	else
		return false;
}
