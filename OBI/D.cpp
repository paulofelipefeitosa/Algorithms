#include <bits/stdc++.h>
using namespace std;
int main()
{
	int vet[10][10];
	char dig[10][7];
	int senha[6];
	int n, cont = 1;
	while(cin>>n, n)
	{
		cout<<"Teste "<<cont++<<endl;
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < 10;j++)
				scanf("%d", &vet[i][j]);
			for(int j = 0;j < 6;j++)
			{
				getchar();
				dig[i][j] = getchar();
			}
		}
		for(int i = 0;i < 6;i++)
		{
			int id, ocur[10] = {};
			for(int j = 0;j < n;j++)
			{
				id = (dig[j][i] - 'A')*2;
				//printf("%c : %d : %d %d\n", dig[j][i], id, vet[j][id], vet[j][id+1]);
				ocur[vet[j][id]]++;
				ocur[vet[j][id+1]]++;
			}
			for(int j = 0;j < 10;j++)
				if(ocur[j] == n)
					senha[i] = j;
		}
		for(int i = 0;i < 6;i++)
			printf("%d ", senha[i]);
		printf("\n\n");
	}
	
	return 0;
}
