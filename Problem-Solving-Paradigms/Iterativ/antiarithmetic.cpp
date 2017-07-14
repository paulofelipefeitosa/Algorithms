#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
int pos[MAX], vet[MAX], n;
int main()
{
	int less, num;
	bool f;
	while(scanf("%d", &n) && n)
	{
		f = false;
		scanf(":");
		for(int i=0;i<n;i++)
		{
			scanf("%d", &vet[i]);
			pos[vet[i]] = i;
		}
		less = n-1;
		for(int i=1;i<less && !f;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				num = (vet[i]<<1) - vet[j];
				if(num>=0 && num<n && pos[num]>i)//achou
				{
					f = true;
					break;
				}
			}
		}
		if(f)
			puts("no");
		else
			puts("yes");
	}
	return 0;
}
