#include <bits/stdc++.h>
#define MAX 2005
using namespace std;
int tree[(MAX*MAX)<<1] = {}, pos[MAX][MAX], mx = 0;

int gcd(int a, int b);
void build(int p, int x1, int y1, int x2, int y2);
void update(int x, int y, int val);
int query(int p, int x1, int y1, int x2, int y2, int qx1, int qy1, int qx2, int qy2);

int main()
{
	int q, x, y, d;
	char s[10];
	build(1, 1, 1, 2002, 2002);
	while(scanf("%d", &q) != EOF)
	{
		while(q--)
		{
			scanf("%s %d %d %d", s, &x, &y, &d);
			x += 501;
			y += 501;
			if(s[0] == 'Q')
				printf("%d\n", query(1, 1, 1, 2002, 2002, x-d+y, x-d-y+1001, x+d+y, x+d-y+1001));
			else
				update(x+y, x-y+1001, d);
		}
		for(int i = 1;i <= mx;i++)
			tree[i] = 0;
		mx = 0;
	}
	return 0;
}
void build(int p, int x1, int y1, int x2, int y2)
{
	if(x1 > x2 || y1 > y2)
		return;
	
	if(x1 == x2 && y1 == y2)
	{
		pos[x1][y1] = p;
		return;
	}
	
	int midx = (x1+x2)>>1, midy = (y1+y2)>>1, child = p<<2;		
	build(child-2, x1, y1, midx, midy);						//Dividir em quatro partes
	build(child-1, midx+1, y1, x2, midy);					//problema -> algum filho pode nao existir (matrix nao quadrada)
	build(child, x1, midy+1, midx, y2);
	build(child+1, midx+1, midy+1, x2, y2);
}
int query(int p, int x1, int y1, int x2, int y2, int qx1, int qy1, int qx2, int qy2)
{
	if(x1 > qx2 || y1 > qy2 || x2 < qx1 || y2 < qy1 || x1 > x2 || y1 > y2)
		return 0;
	if(x1 >= qx1 && y1 >= qy1 && x2 <= qx2 && y2 <= qy2)
		return tree[p];
	
	int midx = (x1+x2)>>1, midy = (y1+y2)>>1, child = p<<2;
	int one = gcd(query(child-2, x1, y1, midx, midy, qx1, qy1, qx2, qy2), query(child-1, midx+1, y1, x2, midy, qx1, qy1, qx2, qy2));
	int two = gcd(query(child, x1, midy+1, midx, y2, qx1, qy1, qx2, qy2), query(child+1, midx+1, midy+1, x2, y2, qx1, qy1, qx2, qy2));
	return gcd(one, two);
}
void update(int x, int y, int val)
{
	int p = pos[x][y];
	mx = max(mx, p);
	tree[p] = val;
	while(p = (p+2)>>2)
	{
		int child = p<<2;
		tree[p] = gcd(gcd(tree[child-2], tree[child-1]), gcd(tree[child], tree[child+1]));
	}
}
int gcd(int a, int b)
{
	int r;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
