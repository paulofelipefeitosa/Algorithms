#include <bits/stdc++.h>
using namespace std;
int main()
{
	bool reach[2][210] = {};
	int tam_g[25], price[25][25];
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int m, c;
		scanf("%d %d", &m, &c);
		for(int i = 0;i < c;i++)
		{
			scanf("%d", &tam_g[i]);
			for(int j = 0;j < tam_g[i];j++)
				scanf("%d", &price[i][j]);
		}
		
		int prev = 0, next = 1;
		
		for(int j = 0;j < tam_g[0];j++)//caso base
			if(m - price[0][j] >= 0)
				reach[prev][m - price[0][j]] = true;
		
		for(int g = 1;g < c;g++)//construo a transição dos casos
		{
			for(int money = 0;money < m;money++)//se eu consigo chegar na garment g com money
			{
				if(reach[prev][money] == true)
					for(int k = 0;k < tam_g[g];k++)
						if(money - price[g][k] >= 0)//faço a transição para os proximos casos
							reach[next][money - price[g][k]] = true;
				reach[prev][money] = false;//limpar a memoria anterior
			}
			swap(prev, next);
		}
		
		int money;
		for(money = 0;money <= m && reach[prev][money] == false;money++);
		
		if(money == (m+1))
			puts("no solution");
		else
			printf("%d\n", m-money);
		
		for(int i = 0;i < 2;i++)
			for(int j = 0;j <= m;j++)
				reach[i][j] = false;
	}
	return 0;
}
