#include <bits/stdc++.h>
using namespace std;
bool comp(int aa, int bb);
int b[2005] = {};
int main()
{
	int n, m;
	int a[2005], like[2005];
	scanf("%d %d", &n, &m);
	int minn = n/m, res = n%m, qt = 0;
	for(int i = 1;i <= m;i++)
		like[i] = i;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &a[i]);
		if(a[i] <= m)
			b[a[i]]++;
	}
	sort(like+1, like+m+1, comp);
	int cont = 0, l = 1;
	bool flag = false;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] > m)
		{
			if(b[like[l]] < minn)
			{
				b[like[l]]++;
				a[i] = like[l];
				cont++;
			}
			else
			{
				l = min(m, ++l);
				if(b[like[l]] < minn)
				{
					b[like[l]]++;
					a[i] = like[l];
					cont++;
				}
				else
				{
					flag = true;
					break;
				}
			}
		}
	}
	if(flag)
	{
		printf("%d %d\n", minn, cont);
		for(int i = 1;i <= n;i++)
			printf("%d ", a[i]);
		putchar('\n');
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		if(minn + 1 == b[a[i]])
		{
			if(qt < res)
				qt++;
			else
			{
				b[a[i]]--;
				if(b[like[l]] < minn)
				{
					b[like[l]]++;
					a[i] = like[l];
					cont++;
				}
				else
				{
					l = min(m, ++l);
					if(b[like[l]] < minn)
					{
						b[like[l]]++;
						a[i] = like[l];
						cont++;
					}
					else
						break;
				}
			}
		}
		else if(minn + 1 < b[a[i]])
		{
			b[a[i]]--;
			if(b[like[l]] < minn)
			{
				b[like[l]]++;
				a[i] = like[l];
				cont++;
			}
			else
			{
				l = min(m, ++l);
				if(b[like[l]] < minn)
				{
					b[like[l]]++;
					a[i] = like[l];
					cont++;
				}
				else
					break;
			}
		}
	}
	printf("%d %d\n", minn, cont);
	for(int i = 1;i <= n;i++)
		printf("%d ", a[i]);
	putchar('\n');
	return 0;
}
bool comp(int aa, int bb)
{
	return b[aa] < b[bb];
}
