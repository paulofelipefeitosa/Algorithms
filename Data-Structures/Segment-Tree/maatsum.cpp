#include <stdio.h>
#include <string.h>
#define  ms0(s) memset(s,0,sizeof s)

#define SZ 1030

int bit[SZ][SZ], data[SZ][SZ], n;

void update(int r, int c, int val)
{
    int i,j;
	for (i = r; i <= n; i += i & -i)
		for (j = c; j <= n; j += j & -j)
			bit[i][j] += val;
}

int sum(int r, int c)
{
	int i,j,s = 0;
	for (i = r; i ; i &= i - 1)
		for (j = c; j ; j &= j - 1)
			s += bit[i][j];
	return s;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);

		ms0(bit); ms0(data);

		char s[5];

		while(scanf("%s", s))
		{
			if(s[1]=='E')
            {
				int r,c,val;

				scanf("%d %d %d",&r,&c,&val);
				r++,c++;
				update(r, c, -data[r][c] + val);
				data[r][c] = val;
			}
			else if(s[1]=='U')
			{
                int r1,c1,r2,c2;

				scanf("%d %d %d %d",&r1,&c1,&r2,&c2);

				r1++,c1++,r2++,c2++;

                int res = sum(r2, c2);
                res-=sum(r1 - 1, c2);
                res-=sum(r2, c1 - 1);
                res+=sum(r1 - 1, c1 - 1);

				printf("%d\n",res);
			}
			else
                break;
		}
		putchar('\n');
	}
	return 0;
}
