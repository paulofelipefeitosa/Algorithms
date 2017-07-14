#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[5];
	while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]), a[0] || a[1] || a[2] || a[3] || a[4])
	{
		bool sol = false;
		int p1, p2, p3, p4;
		sort(a, a+5);
		do
		{
			for(int i = 0;i < 3 && !sol;i++)
			{
				if(i == 0)
					p1 = a[0] + a[1];
				else if(i == 1)
					p1 = a[0] - a[1];
				else
					p1 = a[0] * a[1];
				for(int j = 0;j < 3 && !sol;j++)
				{
					if(j == 0)
						p2 = p1 + a[2];
					else if(j == 1)
						p2 = p1 - a[2];
					else
						p2 = p1 * a[2];
					for(int k = 0;k < 3 && !sol;k++)
					{
						if(k == 0)
							p3 = p2 + a[3];
						else if(k == 1)
							p3 = p2 - a[3];
						else
							p3 = p2 * a[3];
						for(int l = 0;l < 3 && !sol;l++)
						{
							if(l == 0)
								p4 = p3 + a[4];
							else if(l == 1)
								p4 = p3 - a[4];
							else
								p4 = p3 * a[4];
							
							if(p4 == 23)
								sol = true;
						}
					}
				}
			}
		}while(!sol && next_permutation(a, a+5));
		if(sol)
			puts("Possible");
		else
			puts("Impossible");
	}
	return 0;
}
