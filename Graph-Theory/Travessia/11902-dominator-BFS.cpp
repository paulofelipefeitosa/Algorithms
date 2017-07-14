#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int n, num;
char reached[MAX][MAX];
char cab[MAX<<1], respo[MAX<<1];
vector<int>lista_adj[MAX];
void bfs(int ori, int X);
int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d", &n);
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
			{
				if(j < n && k < n)
				{
					scanf("%d", &num);
					if(num)
						lista_adj[j].push_back(k);
				}
				reached[j][k] = 0;
			}
		
		printf("Case %d:\n", i);
		cab[0] = '+';
		for(int j=1;j<=((n-1)<<1) + 1;j++)
			cab[j] = '-';
		cab[n<<1] = '+';
		cab[(n<<1)+1] = '\0';
		printf("%s\n", cab);
		
		bfs(0, n);
		for(int j=0;j<n;j++)
		{
			int idx = 0;
			bfs(0, j);
			for(int k=0;k<n;k++)
			{
				respo[idx++] = '|';
				if(reached[n][k] == 0 || reached[j][k] == 1)//Nao posso chegar 
					respo[idx++] = 'N';
				else
					respo[idx++] = 'Y';
			}
			respo[idx++] = '|';
			respo[idx] = '\0';
			printf("%s\n", respo);
			printf("%s\n", cab);
		}
		for(int k=0;k<n;k++)
			lista_adj[k].clear();
	}
	return 0;
}
void bfs(int ori, int X)
{
	if(ori == X)
		return;
	queue<int>fila;
	int u, v;
	fila.push(ori);
	reached[X][ori] = 1;
	while(!fila.empty())
	{
		u = fila.front();
		fila.pop();
		for(int i=0;i<lista_adj[u].size();i++)
		{
			v = lista_adj[u][i];
			if(v != X && reached[X][v] == 0)
			{
				fila.push(v);
				reached[X][v] = 1;
			}
		}
	}
}
