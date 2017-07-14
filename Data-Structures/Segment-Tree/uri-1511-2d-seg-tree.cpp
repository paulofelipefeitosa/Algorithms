#include <bits/stdc++.h>
#define MAX 2005
using namespace std;
int tree[(MAX*MAX)<<1];

int gcd(int a, int b);
int update(int p, int x1, int y1, int x2, int y2, int x, int y, int val);
int query(int p, int x1, int y1, int x2, int y2, int qx1, int qy1, int qx2, int qy2);

int main()
{	
	int q, x, y, d;
	char s[10];
	while(scanf("%d", &q) != EOF)
	{
		memset(tree, 0, sizeof(tree));
		while(q--)
		{
			scanf("%s %d %d %d", s, &x, &y, &d);
			x += 501;
			y += 501;
			if(s[0] == 'Q')
				printf("%d\n", query(1, 1, 1, 2002, 2002, x-d+y, x-d-y+1001, x+d+y, x+d-y+1001));
			else
				update(1, 1, 1, 2002, 2002, x+y, x-y+1001, d);
		}
	}
	return 0;
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
int update(int p, int x1, int y1, int x2, int y2, int x, int y, int val)
{
	if(x1 > x2 || y1 > y2)
		return 0;
	
	if (x1 > x || y1 > y || x2 < x || y2 < y)
		return tree[p];
	
	if(x == x1 && y == y1 && x == x2 && y == y2)
		return tree[p] = val;
	
	int midx = (x1+x2)>>1, midy = (y1+y2)>>1, child = p<<2;
	int one = gcd(update(child-2, x1, y1, midx, midy, x, y, val), update(child-1, midx+1, y1, x2, midy, x, y, val));
	int two = gcd(update(child, x1, midy+1, midx, y2, x, y, val), update(child+1, midx+1, midy+1, x2, y2, x, y, val));
	return tree[p] = gcd(one, two);
}
int gcd(int a, int b)
{
	int q, r;
	while(b != 0)
	{
		q = a / b;
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
