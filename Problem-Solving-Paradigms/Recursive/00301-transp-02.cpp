#include <bits/stdc++.h>
using namespace std;
struct TICKET
{
	int st, ds, ps, cs;
};
TICKET ticket[25];
int m, o, out[10];
bool comp(TICKET a, TICKET b);
int backtrack(int i, int lst, int cap);
int main()
{
	int n;
	while(scanf("%d %d %d", &n, &m, &o), n || m || o)
	{
		for(int i = 0;i < o;i++)
		{
			scanf("%d %d %d", &ticket[i].st, &ticket[i].ds, &ticket[i].ps);
			ticket[i].cs = (ticket[i].ds - ticket[i].st)*ticket[i].ps;
		}
		sort(ticket, ticket+o, comp);
		
		printf("%d\n", backtrack(0, 0, n));
	}
	return 0;
}
int backtrack(int i, int lst, int cap)
{
	if(i == o)
		return 0;
	
	for(int j = lst+1;j <= ticket[i].st;j++)
		cap += out[j];
	
	int m = backtrack(i+1, ticket[i].st, cap);
	
	if(ticket[i].ps <= cap)
	{
		out[ticket[i].ds] += ticket[i].ps;
		m = max(m, ticket[i].cs + backtrack(i+1, ticket[i].st, cap-ticket[i].ps));
		out[ticket[i].ds] -= ticket[i].ps;
	}
	return m;
}
bool comp(TICKET a, TICKET b)
{
	return a.st < b.st;
}
