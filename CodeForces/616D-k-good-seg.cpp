#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	int used[1000005] = {}, ar[500005];
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n;i++)
		scanf("%d", &ar[i]);
	int cont = 1, size = 1, tam;
	int l = 1, ansl = 1, r = 2, ansr = 1;
	used[ar[l]]++;
	while(r <= n)
	{
		if(used[ar[r]])
		{
			tam = r-l+1;
			if(tam > size)
			{
				size = tam;
				ansl = l;
				ansr = r;
			}
			used[ar[r++]]++;
		}
		else
		{
			if(cont < k)
			{
				tam = r-l+1;
				if(tam > size)
				{
					size = tam;
					ansl = l;
					ansr = r;
				}
				used[ar[r++]]++;
				cont++;
			}
			else
			{
				//printf("%d 3\n", r);
				while(--used[ar[l++]]);
				used[ar[r++]]++;
			}
		}
	}
	printf("%d %d\n", ansl, ansr);
	return 0;
}
