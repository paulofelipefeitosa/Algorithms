#include <bits/stdc++.h>
using namespace std;
char caca[105][105];
int n, m;
bool can(int i, int j, char str[]);
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0;i < n;i++)
		scanf("%s", caca[i]);
	char str[105];
	int q;
	scanf("%d", &q);
	while(q--)
	{
		bool flag = false;
		scanf("%s", str);
		for(int i = 0;i < n && !flag;i++)
			for(int j = 0;j < m && !flag;j++)
				if(can(i, j, str))
				{
					printf("%d %d\n", i+1, j+1);
					flag = true;
				}
		if(!flag)
			puts("-1");
	}
	return 0;
}
bool can(int i, int j, char str[])
{
	char strs[8][105];
	int combi[8] = {1, -1, 1, -1, 1, 0, 0, -1};
	int combj[8] = {1, -1, -1, 1, 0, 1, -1, 0};
	for(int k = 0;k < 8;k++)
	{
		int ii = i, jj = j, p = 0;
		while(ii < n && ii > -1 && jj < m && jj > -1)
		{
			strs[k][p] = caca[ii][jj];
			ii += combi[k];
			jj += combj[k];
			p++;
		}
		strs[k][p] = '\0';
		int tam1 = strlen(strs[k]);
		int tam2 = strlen(str);
		if(tam1 >= tam2)
		{
			bool flag = true;
			for(int l = 0;l < tam2 && flag;l++)
				if(str[l] != strs[k][l])
					flag = false;
			if(flag)
				return true;
		}
	}
	return false;
}
