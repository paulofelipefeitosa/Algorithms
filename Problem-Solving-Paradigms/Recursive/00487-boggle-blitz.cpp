#include <bits/stdc++.h>
using namespace std;
char mat[25][25], word[410];
bool marq[25][25] = {};
int cbi[] = {1, -1, 1, -1, 1, -1, 0, 0};
int cbj[] = {1, -1, -1, 1, 0, 0, 1, -1}, n;
set<string>ans[410];
void backtrack(int i, int j, int cont);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%s", &mat[i]);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
			{
				marq[i][j] = true;
				word[0] = mat[i][j];
				backtrack(i, j, 1);
				marq[i][j] = false;
			}
		for(int i = 3;i < 401;i++)
		{
			for(auto it = ans[i].begin();it != ans[i].end();it++)
				cout<<*it<<endl;
			ans[i].clear();
		}
		if(t)
			putchar('\n');
	}
	return 0;
}
void backtrack(int i, int j, int cont)
{
	int k, l;
	for(int o = 0;o < 8;o++)
	{
		k = i + cbi[o];
		l = j + cbj[o];
		if(k > -1 && k < n && l > -1 && l < n && mat[i][j] < mat[k][l] && !marq[k][l])
		{
			marq[k][l] = true;
			word[cont] = mat[k][l];
			backtrack(k, l, cont+1);
			marq[k][l] = false;
		}
	}
	if(cont > 2)
	{
		word[cont] = '\0';
		ans[cont].insert(word);
	}
}
