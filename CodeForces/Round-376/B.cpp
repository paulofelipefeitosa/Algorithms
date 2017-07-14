#include <bits/stdc++.h>
#define geti(a) scanf("%d", &a)
#define getii(a, b) scanf("%d %d", &a, &b)
#define getiii(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pf printf
#define sc scanf
#define rep(a, b, x) for(int x = a;x < b;x++)
#define reu(a, b, x) for(int x = a;x <= b;x++)
#define pi pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define pq priority_queue
using namespace std;
int main()
{
	int n, vet[200005];
	bool flag = true;
	geti(n);
	rep(0, n, i)
	{
		geti(vet[i]);
	}
	int p1 = 0;
	while(p1 < n)
	{
		if(vet[p1] & 1)
		{
			if(p1+1 < n)
			{
				if(vet[p1+1])
				{
					vet[p1+1]--;
					vet[p1] = 0;
				}
				else
				{
					flag = false;
					break;
				}
			}
			else
			{
				flag = false;
				break;
			}
		}
		else
			vet[p1] = 0;
		p1++;
	}
	if(flag)
		pf("YES\n");
	else
		pf("NO\n");
	return 0;
}
