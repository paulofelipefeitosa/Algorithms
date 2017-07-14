#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 100005
using namespace std;
pair<int, int>interval[MAX];
int main()
{
	int m, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &m);
		int a, b, cont = 0;
		while(scanf("%d %d", &a, &b), (a || b))
			interval[cont++] = pair<int,int>(a, b);
			
		sort(interval, interval+cont);
		
		vector<pair<int,int> >sols;
		pair<int,int>best;
		int required = 0;
		bool valid = false, reach = false;
		
		for(int i = 0;i < cont;i++)
		{
			if(interval[i].first <= required)
			{
				if(interval[i].second > best.second)
				{
					best = interval[i];
					valid = true;
				}
			}
			else
			{
				if(valid)
				{
					sols.push_back(best);
					required = best.second;
					valid = false;
					if(required >= m)
					{
						reach = true;
						break;
					}
				}
				if(interval[i].first <= required)
				{
					if(interval[i].second > best.second)
					{
						best = interval[i];
						valid = true;
					}
				}
				else
					break;
			}
		}
		if(valid)
		{
			sols.push_back(best);
			if(best.second >= m)
				reach = true;
		}
		
		if(reach)
		{
			printf("%d\n", sols.size());
			for(int i = 0;i < (int)sols.size();i++)
				printf("%d %d\n", sols[i].first, sols[i].second);
		}
		else
			puts("0");
		
		if(t)
			putchar('\n');
	}
	return 0;
}
