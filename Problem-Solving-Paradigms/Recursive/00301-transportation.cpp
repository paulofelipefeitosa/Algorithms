#include <bits/stdc++.h>
using namespace std;
struct TICKET
{
	int st, ds, ps;
};
TICKET ticket[25];
int m, o, out[10];
pair<int,int>idx[10];
bool comp(TICKET a, TICKET b);
int backtrack(int i, int cap);
int main()
{
	int n;
	while(scanf("%d %d %d", &n, &m, &o), n || m || o)
	{
		for(int i = 0;i < o;i++)
			scanf("%d %d %d", &ticket[i].st, &ticket[i].ds, &ticket[i].ps);
		sort(ticket, ticket+o, comp);
		
		int pt = 0, j, k;
		for(int i = 0;i <= m;i++)
		{
			out[i] = 0;
			for(j = pt;j < o && i != ticket[j].st;j++);
			for(k = j;k < o && i == ticket[k].st;k++);
			if(j < o)
			{
				idx[i] = pair<int,int>(j, k);
				pt = k;
			}
			else
				idx[i] = pair<int,int>(0, 0);
		}
		printf("%d\n", backtrack(0, n));
	}
	return 0;
}
int backtrack(int i, int cap)
{
	if(i == m)
		return 0;
	cap += out[i];
	
	int j = idx[i].first, k = idx[i].second;
	int ele = k - j, tam = 1<<ele;
	int m = 0;
	for(int sub = 0;sub < tam;sub++)
	{
		int pa = 0, cus = 0;
		for(int l = 0;l < ele;l++)
			if(sub & (1<<l))
			{
				pa += ticket[j+l].ps;
				cus += (ticket[j+l].ds - ticket[j+l].st)*ticket[j+l].ps;
			}
			
		if(pa <= cap)
		{
			for(int l = 0;l < ele;l++)
				if(sub & (1<<l))
					out[ticket[j+l].ds] += ticket[j+l].ps;
					
			m = max(m, cus + backtrack(i+1, cap-pa));
			
			for(int l = 0;l < ele;l++)
				if(sub & (1<<l))
					out[ticket[j+l].ds] -= ticket[j+l].ps;
		}
	}
	return m;
}
bool comp(TICKET a, TICKET b)
{
	return a.st < b.st;
}
