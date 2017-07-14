#include <bits/stdc++.h>
#define MAX 105
using namespace std;
struct AGENCY
{
	char str[20];
	int w;
};
bool comp(AGENCY A, AGENCY B)
{
	if(A.w == B.w)
		return strncmp(A.str, B.str, 16) <= 0 ? true : false;
	return A.w < B.w;
}
int main()
{
	int t;
	AGENCY agen[MAX];
	scanf("%d", &t);
	for(int k = 1;k <= t;k++)
	{
		int n, m, l;
		scanf("%d %d %d", &n, &m, &l);
		int x = (int)(log2((double)n) - log2((double)m)), a, b;
		//printf("%d\n", x);
		for(int i = 0;i < l;i++)
		{
			scanf("\n%[^:]s", agen[i].str);
			scanf(":%d,%d", &a, &b);
			int cust = 0, actual = n, diff;
			for(int j = 0;j < x;j++)
			{
				diff = actual - (actual>>1);
				cust += min(diff*a, b);
				actual>>=1;
			}
			if(actual == m)
				agen[i].w = cust;
			else
				agen[i].w = cust + (actual - m)*a;
		}
		sort(agen, agen+l, comp);
		printf("Case %d\n", k);
		for(int i = 0;i < l;i++)
			printf("%s %d\n", agen[i].str, agen[i].w);
	}
	return 0;
}

