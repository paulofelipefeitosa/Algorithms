#include <bits/stdc++.h>
#define lsone(x) x & (-x)
#define MAX 1030
using namespace std;
int bit[MAX][MAX] = {}, mat[MAX][MAX], n;
int sum(int x, int y);
int query(int x1, int y1, int x2, int y2);
void update(int x, int y, int val);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		char op[5];
		while(scanf("%s", op), op[0] != 'E')
		{
			if(op[1] == 'E')
			{
				int x, y, num;
				scanf("%d %d %d", &x, &y, &num);
				x++; y++;
				update(x, y, num - mat[x][y]);
				mat[x][y] = num;
			}
			else
			{
				int x1, y1, x2, y2;
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				x1++; y1++; x2++; y2++;
				printf("%d\n", query(x1, y1, x2, y2));
			}
		}
		for(int i = 0;i <= n;i++)
			for(int j = 0;j <= n;j++)
				mat[i][j] = bit[i][j] = 0;
	}
	return 0;
}
int query(int x1, int y1, int x2, int y2)
{
	return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
}
int sum(int x, int y)
{
	int sum = 0;
	while(x > 0)
	{
		int j = y;
		while(j > 0)
		{
			sum += bit[x][j];
			j -= lsone(j);
		}
		x -= lsone(x);
	}
	return sum;
}
void update(int x, int y, int val)
{
	while(x <= n)
	{
		int j = y;
		while(j <= n)
		{
			bit[x][j] += val;
			j += lsone(j);
		}
		x += lsone(x);
	}
}
