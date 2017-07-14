#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int n, num;
char reached[MAX][MAX];
char cab[MAX<<1], respo[MAX<<1];
vector<int>lista_adj[MAX];
void dfs(int ori, int X);
int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d", &n);
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			{
				scanf("%d", &num);
				if(num)
					lista_adj[j].push_back(k);
			}
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				reached[j][k] = 0;
		printf("Case %d:\n", i);
		cab[0] = '+';
		for(int j=1;j<=((n-1)<<1) + 1;j++)
			cab[j] = '-';
		cab[n<<1] = '+';
		cab[(n<<1)+1] = '\0';
		printf("%s\n", cab);
		
		dfs(0, n);
		for(int j=0;j<n;j++)
		{
			int idx = 0;
			dfs(0, j);
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
void dfs(int ori, int X)
{
	if(ori == X)
		return;
	int u;
	reached[X][ori] = 1;
	for(int i=0;i<lista_adj[ori].size();i++)
	{
		u = lista_adj[ori][i];
		if(reached[X][u]==0)
			dfs(u, X);
	}
}
