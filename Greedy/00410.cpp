#include <bits/stdc++.h>
#define MAX 15
using namespace std;
int main()
{
	int c, s, cont = 1;
	double m, imb;
	int vet[MAX], tam;
	list<int>init;
	while(scanf("%d %d", &c, &s)!=EOF)
	{
		m = 0;
		for(int i = 0;i < s;i++)
		{
			scanf("%d", &vet[i]);
			init.push_back(vet[i]);
			m += vet[i];
		}
		m = m/c;
		tam = c<<1;
		for(int i = s;i < tam;i++)
			vet[i] = 0;
		sort(vet, vet+tam);
		int pos1, val, pos2, ex;
		printf("Set #%d\n", cont++);
		imb = 0;
		for(int j = 0;j < c;j++)
		{
			if(!init.empty())
			{
				val = init.front();
				init.pop_front();
				pos1 = lower_bound(vet, vet+tam, val) - vet;
				pos2 = (tam-1) - pos1;
				ex = vet[pos2];
				imb += abs(m - (val + ex));
				if(ex == 0)
					printf(" %d: %d\n", j, vet[pos1]);
				else
				{
					printf(" %d: %d %d\n", j, vet[pos1], vet[pos2]);
					for(list<int>::iterator it = init.begin();it != init.end();it++)
						if(*it == ex)
						{
							init.erase(it);
							break;
						}
				}
			}
			else
			{
				imb += m;
				printf(" %d:\n", j);
			}
		}
		printf("IMBALANCE = %.5lf\n\n", imb);
	}
	return 0;
}
