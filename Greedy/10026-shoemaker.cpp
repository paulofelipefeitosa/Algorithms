#include <bits/stdc++.h>
using namespace std;
struct TASK
{
	int day, cust, id;
};
struct comp
{
	bool operator()(TASK a, TASK b)
	{
		double fi = ((double)a.cust)/a.day;
		double se = ((double)b.cust)/b.day;
		if(fi == se)
			return a.id > b.id;
		return fi < se;
	}
};
int main()
{
	int t;
	priority_queue<TASK, vector<TASK>, comp>fila;
	scanf("%d", &t);
	while(t--)
	{
		int n, x, y;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d %d", &x, &y);
			fila.push((TASK){x, y, i});
		}
		TASK cur;
		cur = fila.top();
		printf("%d", cur.id);
		fila.pop();
		while(!fila.empty())
		{
			cur = fila.top();
			printf(" %d", cur.id);
			fila.pop();
		}
		if(t)
			printf("\n\n");
		else
			putchar('\n');
	}
	return 0;
}
