#include <bits/stdc++.h>
using namespace std;
int main()
{
	int mat[105], t;
	scanf("%d", &t);
	while(t--)
	{
		int p, n, num;
		scanf("%d %d", &p, &n);
		for(int i = 0;i < n;i++)
		{
			mat[i] = 0;
			for(int j = 0;j < p;j++)
			{
				scanf("%d", &num);
				if(num)
					mat[i] |= (1<<j);
			}
		}
		int qnt = (1<<p), cpy[105], ans = (1<<30);
		map<int, bool>mapa;
		for(int sett = 0;sett < qnt;sett++)
		{
			int cont = 0;
			for(int j = 0;j < p;j++)
				if(sett & (1<<j))
					cont++;
					
			bool flag = true;
			for(int j = 0;j < n && flag;j++)
			{
				num = mat[j] & sett;
				if(mapa.find(num) != mapa.end())
					flag = false;
				else
					mapa[num] = true;
			}
			if(flag)
				ans = min(ans, cont);
			mapa.clear();
		}
		printf("%d\n", ans);
	}
	return 0;
}
