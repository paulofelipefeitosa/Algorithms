#include <bits/stdc++.h>
#define MAX_TAM_MATRIX 1005
using namespace std;

int matrix[MAX_TAM_MATRIX][MAX_TAM_MATRIX] = {};
int n, m;

int BFS(pair<int,int>ori, pair<int,int>des);

int main()
{
	pair<int,int>ori, des;
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
		{
			cin>>matrix[i][j];
			if(matrix[i][j] == 2)				//vertice de origem da busca :)
				ori = pair<int,int>(i,j);
			else if(matrix[i][j] == 3)			//vertice de destino da busca :)
				des = pair<int,int>(i,j);
		}
		
	cout<<"Para sair de ("<<ori.first<<", "<<ori.second<<") e chegar a ("<<des.first<<", "<<des.second<<") na matrix ";
	cout<<"sao necessarios "<<BFS(ori, des)<<" passos."<<endl;
	
	return 0;
}
int BFS(pair<int,int>ori, pair<int,int>des)
{
	queue<pair<int,int> >fila;		//fila de par, pois nossos vertices agora são elementos de uma matrix, ou seja, um par ordenado (i,j)
	
	map<pair<int,int>, int>mark;
	
	int comb_i[] = {1, -1, 0, 0};
	int comb_j[] = {0, 0, 1, -1};	//as combinações para visitar os vertices vizinhos, que nesse caso são (i+1, j), (i-1, j), (i, j+1) e (i, j-1)
	
	fila.push(ori);
	mark[ori] = 1;					//vertice de destino sempre igual a 1, se igual 0 significa que ele nao foi visitado ainda
	
	while(!fila.empty())			//faça enquanto a fila nao estiver vazia
	{
		pair<int,int> u = fila.front();
		
		fila.pop();
		
		for(int k = 0;k < 4;k++)
		{
			pair<int,int> v = pair<int,int>(u.first + comb_i[k], u.second + comb_j[k]);		// v são os vertices vizinhos do vertice u
			
			if(matrix[v.first][v.second] == 1 || matrix[v.first][v.second] == 3)			//alem disso Alice deve ter deixado uma estrela na sala
				if((v.first >= 1) && (v.first <= n) && (v.second >= 1) && (v.second <= m))	//nao sai das bordas da matrix
					if(mark[v] == 0)														//nao foi visitado ainda
					{
						mark[v] = mark[u] + 1;		//v é vizinho de u
						fila.push(v);
						
						if(v == des)
							return mark[v];
					}
		}
	}
	
	return -1;						//nao conseguiu chegar
}
