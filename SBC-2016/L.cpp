#include <bits/stdc++.h>
using namespace std;
int h, l;
int mat[205][205];
bool marq[205][205] = {};
int bfs(pair<int,int>ori, int val);
int main()
{
	scanf("%d %d", &h, &l);
	for(int i = 0;i < h;i++)
		for(int j = 0;j < l;j++)
			scanf("%d", &mat[i][j]);
	int minn = 1<<30;
	for(int i = 0;i < h;i++)
		for(int j = 0;j < l;j++)
			if(marq[i][j] == false)
				minn = min(minn, bfs(pair<int,int>(i, j), mat[i][j]));
	printf("%d\n", minn);
	return 0;
}
int bfs(pair<int,int>ori, int val)
{
	queue<pair<int,int> >fila;
	pair<int,int>v;
	int cbi[] = {1, 0, -1, 0};
	int cbj[] = {0, 1, 0, -1};
	int cont = 1, j, k;
	fila.push(ori);
	marq[ori.first][ori.second] = true;
	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();
		for(int i = 0;i < 4;i++)
		{
			j = v.first + cbi[i];
			k = v.second + cbj[i];
			if(j < h && j > -1 && k < l && k > -1 && marq[j][k] == false && mat[j][k] == val)
			{
				fila.push(pair<int,int>(j, k));
				marq[j][k] = true;
				cont++;
			}
		}
	}
	return cont;
}
