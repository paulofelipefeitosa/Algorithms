#include <bits/stdc++.h>
#define EPS 1e-9
#define MAXS 30
#define MAXE 55
using namespace std;
struct EVENT
{
	int st, type, li;
};
EVENT events[MAXE];
int pt;
char value(char s[]);
bool simulate(double tank);
int main()
{
	char str[MAXS];
	int tt;
	while(1)
	{
		pt = 0;
		scanf("%d", &events[pt].st);
		scanf(" %[^0123456789]s", str);
		scanf("%d", &events[pt].li);
		if(events[pt].li == 0)
			break;
		events[pt++].type = 0;
		while(scanf("%d", &events[pt].st))
		{
			scanf(" %[^0123456789\n]s", str);
			tt = value(str);
			if(tt == 0)
			{
				events[pt].type = 0;
				scanf("%d", &events[pt++].li);
			}
			else if(tt == 4)
			{
				events[pt++].type = 4;
				break;
			}
			else
				events[pt++].type = tt;
		}
		double lb = 0.0, up = 10000.00, mid = 0.0, ans = 0.0;
		for(int i = 0;i < 50;i++)
		{
			mid = (up + lb)/2.0;
			if(simulate(mid))
			{
				ans = mid;
				up = mid;
			}
			else
				lb = mid;
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
bool simulate(double tank)
{
	//printf("Tank = %.3lf\n", tank);
	double actank = tank, consu = events[0].li/100.00;
	int leak = 0, dist;
	for(int i=1;i<pt;i++)
	{
		dist = events[i].st - events[i-1].st;
		actank -= (leak * dist) + (dist * consu);
		//printf("%d %.3lf with %.3lf\n", dist, actank, consu);
		if(actank < 0)
			return false;
		if(events[i].type == 0)
			consu = events[i].li/100.00;
		else if(events[i].type==1)
			leak++;
		else if(events[i].type==2)
			actank = tank;
		else if(events[i].type==3)
			leak = 0;
		else
			return true;
	}
}
char value(char s[])
{
	if(strcmp(s, "Fuel consumption ") == 0)
		return 0;
	if(strcmp(s, "Leak") == 0)
		return 1;
	if(strcmp(s, "Gas station") == 0)
		return 2;
	if(strcmp(s, "Mechanic") == 0)
		return 3;
	if(strcmp(s, "Goal") == 0)
		return 4;
}
