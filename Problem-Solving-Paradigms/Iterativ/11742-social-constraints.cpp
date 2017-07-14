#include <bits/stdc++.h>
using namespace std;
struct constraint
{
	int n1, n2, v;
};
int main()
{
	int n, m, seat[10];
	constraint cons[25];
	while(scanf("%d %d", &n, &m), (n || m))
	{
		for(int i = 0;i < n;i++)
			seat[i] = i;
		for(int i = 0;i < m;i++)
			scanf("%d %d %d", &cons[i].n1, &cons[i].n2, &cons[i].v);
		int cont = 0;
		do
		{
			bool flag = true;
			for(int i = 0;i < m && flag;i++)
			{
				int dist = abs(seat[cons[i].n1] - seat[cons[i].n2]);
				if(cons[i].v > 0)
				{
					if(!(dist <= cons[i].v))
					 	flag = false;
				}
				else
				{
					if(!(dist >= abs(cons[i].v)))
						flag = false;
				}
			}
			if(flag)
				cont++;
		}while(next_permutation(seat, seat+n));
		printf("%d\n", cont);
	}
	return 0;
}
