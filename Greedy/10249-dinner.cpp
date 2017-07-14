#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int main()
{
	int m, n;
	int num, pilha[MAX], arran[MAX][MAX], pos[MAX];
	pair<int,int>mem[MAX];
	priority_queue<pair<int,int>, vector<pair<int,int> >, less<pair<int,int> > >fila;
	while(scanf("%d %d", &m, &n), (m || n))
	{
		for(int i = 0;i < m;i++)
		{
			scanf("%d", &num);
			mem[i] = pair<int,int>(num, i);
		}
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", &num);
			fila.push(pair<int,int>(num, i));
		}
		sort(mem, mem+m);
		for(int i = 0;i < m;i++)
			pos[mem[i].second] = i;
		bool sol = true;
		for(int i = m-1;i >= 0 && sol;i--)
		{
			if(mem[i].first > fila.size())
				sol = false;
			else
			{
				for(int j = 0;j < mem[i].first;j++)
				{
					pilha[j] = fila.top().first;
					arran[i][j] = fila.top().second;
					fila.pop();
				}
				for(int j = 0;j < mem[i].first;j++)
					if(pilha[j] > 1)
						fila.push(pair<int,int>(pilha[j]-1, arran[i][j]));
			}
		}
		if(!sol)
			puts("0");
		else
		{
			puts("1");
			for(int i = 0;i < m;i++)
			{
				int at = pos[i];
				printf("%d", arran[at][0]);
				for(int j = 1;j < mem[at].first;j++)
					printf(" %d", arran[at][j]);
				putchar('\n');
			}
		}
		while(!fila.empty())
			fila.pop();
	}
	return 0;
}
