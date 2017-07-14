#include <bits/stdc++.h>
#define MAX 260
using namespace std;
vector<char>adj_list[MAX];
bool marc[MAX];
void bfs(char ori);
int main()
{
	int t, cont;
	char n, v1, v2;
	string str;
	scanf("%d", &t);
	getchar();
	getchar();
	while(t--)
	{
		scanf("%c", &n);
		getchar();
		for(char i = 'A';i <= n;i++)
			marc[i] = false;
		do
		{
			v1 = getchar();
			if(v1 == '\n')
				break;
			v2 = getchar();
			adj_list[v1].push_back(v2);
			adj_list[v2].push_back(v1);
		}while(scanf("%c", &v1) != EOF);
		cont = 0;
		for(char i = 'A';i <= n;i++)
			if(marc[i]==false)
			{
				bfs(i);
				cont++;
			}
		printf("%d\n", cont);
		if(t)
			putchar('\n');
		for(char i = 'A';i <= n;i++)
			adj_list[i].clear();
	}
	return 0;
}
void bfs(char ori)
{
	queue<char>fila;
	char u, v;
	fila.push(ori);
	marc[ori] = true;
	while(!fila.empty())
	{
		u = fila.front();
		fila.pop();
		for(int i=0;i<adj_list[u].size();i++)
		{
			v = adj_list[u][i];
			if(marc[v]==false)
			{
				marc[v] = true;
				fila.push(v);
			}
		}
	}
}
