#include <bits/stdc++.h>
#define MAX 525
using namespace std;
char grid[MAX][MAX];
int tree[(MAX*MAX)<<1] = {}, pt = 0;
char ans[MAX*MAX];
void build(int p, int x1, int y1, int x2, int y2);
void travel(int p, int x1, int y1, int x2, int y2);
int main()
{
	int n, num;
	scanf("#define quadtree_width %d\n", &n);
	scanf("#define quadtree_height %d\n", &n);
	scanf("static char quadtree_bits[] = {\n");
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j+=8)
		{
			scanf("%x,", &num);
			for(int k = 0;k < 8;k++)
				if(num & (1<<k))
					grid[i][j+k] = 1;
				else
					grid[i][j+k] = 0;
		}
	build(1, 1, 1, n, n);
	travel(1, 1, 1, n, n);
	ans[pt] = '\0';
	printf("%d\n%s\n", n, ans);
	return 0;
}
void build(int p, int x1, int y1, int x2, int y2)
{
	if(x1 == x2 && y1 == y2)
		tree[p] = grid[x1][y1];
	else
	{
		int midx = (x1+x2)>>1, midy = (y1+y2)>>1, child = p<<2;
		build(child-2, x1, y1, midx, midy);
		build(child-1, x1, midy+1, midx, y2);
		build(child, midx+1, y1, x2, midy);
		build(child+1, midx+1, midy+1, x2, y2);	
		tree[p] = tree[child-2] + tree[child-1] + tree[child] + tree[child+1];
	}
}
void travel(int p, int x1, int y1, int x2, int y2)
{
	if((x2-x1+1)*(y2-y1+1) == tree[p])
		ans[pt++] = 'B';
	else if(tree[p] == 0)
		ans[pt++] = 'W';
	else
	{
		ans[pt++] = 'Q';
		int midx = (x1+x2)>>1, midy = (y1+y2)>>1, child = p<<2;
		travel(child-2, x1, y1, midx, midy);
		travel(child-1, x1, midy+1, midx, y2);
		travel(child, midx+1, y1, x2, midy);
		travel(child+1, midx+1, midy+1, x2, y2);
	}
}
