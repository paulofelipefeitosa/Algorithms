#include <bits/stdc++.h>
#define MAX 75
using namespace std;
char str[MAX][MAX];
int main()
{
	int t, n, ans, lb, ub, tam1, tam2, cont;
	scanf("%d", &t);
	while(t--)
	{
		ans = 0;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%s", str[i]);
		for(int i=0;i<n;i++)
		{
			tam1 = strlen(str[i]);
			for(int j=i+1;j<n;j++)
			{
				tam2 = strlen(str[j]);
				for(lb = tam2 - 1;lb >= 0;lb--)
				{
					cont = 0;
					for(int a = 0, b = lb;a < tam1 && b < tam2;a++, b++)
						if(str[i][a] == str[j][b])
							cont++;
					ans = max(ans, cont);
				}
				for(lb = tam1 - 1;lb >= 0;lb--)
				{
					cont = 0;
					for(int a = 0, b = lb;a < tam2 && b < tam1;a++, b++)
						if(str[i][b] == str[j][a])
							cont++;
					ans = max(ans, cont);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
