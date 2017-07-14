#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 10005
using namespace std;
pair<double, double>interval[MAX];
int main()
{
	int pos, r, n, l;
	double dx, w;
	while(scanf("%d %d %lf", &n, &l, &w)!=EOF)
	{
		w /= 2.0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d", &pos, &r);
			dx = ((double)r*r) - (w*w);
			if(dx < 0)
				dx = 0;
			else
				dx = sqrt(dx);
			interval[i] = pair<double, double>((double)pos - dx, (double)pos + dx);
		}
		sort(interval, interval+n);
		double required = 0.0, rReach = 0.0;
		int i = 0, cont = 0;
		while(rReach < l)
		{
			double bestR = required;
			bool have = false;
			for(;i < n;i++)
			{
				if(interval[i].first > required)
					break;
				if(interval[i].second >= bestR)
				{
					bestR = interval[i].second;
					have = true;
				}
			}
			if(!have)
				break;
			cont++;
			rReach = required = bestR;
		}
		if(rReach < l)
			puts("-1");
		else
			printf("%d\n", cont);
	}
	return 0;
}
