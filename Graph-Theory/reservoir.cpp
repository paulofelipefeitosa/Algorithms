#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
char grid[MAX][MAX];
bool bricks[MAX][MAX] = {};
void bfs(int x, int y, int n, int m);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0;i < n;i++)
			scanf("%s", grid[i]);
		for(int j = 0;j < m;j++)
			if(grid[n-1][j] == 'B' && bricks[n-1][j] == false)
				bfs(n-1, j, n, m);

		/*for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j++)
				printf("%d", (int)bricks[i][j]);
			printf("\n");
		}*/

		int combi[] = {0, 0, 1, -1};
		int combj[] = {1, -1, 0, 0};

		bool flag = true;
		for(int i = 0;i < n && flag;i++)
			for(int j = 0;j < m && flag;j++)
				if(grid[i][j] == 'B' && bricks[i][j] == false)
					flag = false;

		//printf("%d\n", (int)flag);

		for(int i = 0;i < n && flag;i++)
			for(int j = 0;j < m && flag;j++)
				if(grid[i][j] == 'W')
					for(int k = 0;k < 4 && flag;k++)
					{
						int ii = i + combi[k];
						int jj = j + combj[k];
						if(ii < 0 || ii >= n || jj < 0 || jj >= m)
						{
							if(ii >= 0)
								flag = false;
						}
						else
						{
							if(k == 0 || k == 1 || k == 2)
								if(grid[ii][jj] == 'A')
									flag = false;
							if(k == 3)
								if(grid[ii][jj] == 'B')
									flag = false;
						}
					}

		//printf("%d\n", (int)flag);

		for(int i = 0;i < n && flag;i++)
			for(int j = 0;j < m && flag;j++)
				if(grid[i][j] == 'A')
					for(int k = 0;k < 4 && flag;k++)
					{
						int ii = i + combi[k];
						int jj = j + combj[k];
						if(ii < 0 || ii >= n || jj < 0 || jj >= m)
							continue;

						if(k == 0 || k == 1)
							if(grid[ii][jj] == 'W')
								flag = false;
						if(k == 3)
							if(grid[ii][jj] == 'W' || grid[ii][jj] == 'B')
								flag = false;
					}

		//printf("%d\n", (int)flag);

		memset(bricks, false, sizeof(bricks));
		if(flag == false)
			puts("no");
		else
			puts("yes");
		//printf("\n");
	}
	return 0;
}
void bfs(int x, int y, int n, int m)
{
	queue<pair<int,int> >fila;
	fila.push(pair<int,int>(x, y));
	int combi[] = {0, 0, 1, -1};
	int combj[] = {1, -1, 0, 0};
	bricks[x][y] = true;
	while(!fila.empty())
	{
		pair<int,int>v = fila.front();
		fila.pop();
		for(int k = 0;k < 4;k++)
		{
			int ii = v.first + combi[k];
			int jj = v.second + combj[k];
			if(ii < 0 || ii >= n || jj < 0 || jj >= m)
				continue;
			if(grid[ii][jj] == 'B' && bricks[ii][jj] == false)
			{
				fila.push(pair<int,int>(ii, jj));
				bricks[ii][jj] = true;
			}
		}
	}
}