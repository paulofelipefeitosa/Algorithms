#include <bits/stdc++.h>
#define LSOne(x) (x & -x)
#define lli unsigned long long int
#define MAX 1005
#define P 1000000007
using namespace std;
int bit[MAX][MAX] = {}, n, m, last = 1;
lli fat[11000005] = {};

void update(int x, int y, int v);
int query(int x, int y);
int prersq(int x1, int y1, int x2, int y2);
lli calc(int f);
int inv(int a);
int mdc(int a, int b, int *x, int *y);

int main()
{
	char s[55];
	int ft[MAX][MAX] = {}, val[6], pt = 0, cont = 1;
	fat[0] = fat[1] = 1;
	scanf("%d %d", &n, &m);
	getchar();
	while(scanf("%[^\n]s", s) != EOF)
	{
		getchar();
		char *ptr = strtok(s, " ");
		while(ptr != NULL)
		{
			val[pt++] = atoi(ptr);
			ptr = strtok(NULL, " ");
		}
		if(pt == 2)
		{
			update(val[0], val[1], -ft[val[0]][val[1]]);
			ft[val[0]][val[1]] = 0;
		}
		else if(pt == 3)
		{
			update(val[0], val[1], val[2]);
			ft[val[0]][val[1]] += val[2];
		}
		else
		{
			int k = prersq(val[0], val[1], val[2], val[3]);
			if(k == 0)
				printf("Day #%d: 0\n", cont++);
			else
			{
				int n = val[4];
				int fat = n + k - 1;
				lli num = calc(fat);
				lli div = calc(k-1)*calc(n);
				bool flag = false;
				if(div > P)
				{
					div = div%P;
					flag = true;
				}
				if(fat >= 13 || flag)
					printf("Day #%d: %llu\n", cont++, (num*inv(div))%P);
				else
					printf("Day #%d: %llu\n", cont++, num/div);
			}
		}
		pt = 0;
	}
	return 0;
}
lli calc(int f)
{
	if(fat[f] == 0)
	{
		lli ans = fat[last];
		for(int k = last+1;k <= f;k++)
		{
			ans = (ans*k)%P;
			fat[k] = ans;
		}
		last = f;
	}
	return fat[f];
}
int inv(int a)
{
	int x, y, d;
	d = mdc(a, P, &x, &y);
	if(x < 0)
		x += P;
	return x;
}
int mdc(int a, int b, int *x, int *y)
{
	int xx, yy, d;
	if(b == 0)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	d = mdc(b, a%b, &xx, &yy);
	*x = yy;
	*y = xx - a/b*yy;
	return d;
}
int prersq(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) + query(x1-1, y1-1) - query(x1-1, y2) - query(x2, y1-1);
}
int query(int x, int y)
{
	int sum = 0;
	while(x)
	{
		int y1 = y;
		while(y1)
		{
			sum += bit[x][y1];
			y1 -= LSOne(y1);
		}
		x -= LSOne(x);
	}
	return sum;
}
void update(int x, int y, int v)
{
    while(x <= n)
    {
        int y1 = y;
        while(y1 <= m)
        {
            bit[x][y1] += v;
            y1 += LSOne(y1);
        }
        x += LSOne(x);
    }
}
