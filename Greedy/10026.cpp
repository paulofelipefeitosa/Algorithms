#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
struct TASK
{
	int day, cust, id;
};
bool comp(TASK a, TASK b)
{
	double fi = ((double)a.cust)/a.day;
	double se = ((double)b.cust)/b.day;
	if(fi == se)
		return a.id < b.id;
	return fi > se;
};
int main()
{
	int t;
	TASK vet[MAX];
	scanf("%d", &t);
	while(t--)
	{
		int n, x, y;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d %d", &vet[i].day, &vet[i].cust);
			vet[i].id = i;
		}
		sort(vet+1, vet+n+1, comp);
		printf("%d", vet[1].id);
		for(int i = 2;i <= n;i++)
			printf(" %d", vet[i].id);
		if(t)
			printf("\n\n");
		else
			putchar('\n');
	}
	return 0;
}
