#include <bits/stdc++.h>
using namespace std;
double dist[55], pr[55];
double reach, cap, miles, cus;
int n;
double backtrack(int i, double c);
int main()
{
	int cont = 1;
	while(scanf("%lf", &reach), reach >= 0)
	{
		scanf("%lf %lf %lf %d", &cap, &miles, &cus, &n);
		n++;
		for(int i = 1;i < n;i++)
			scanf("%lf %lf", &dist[i], &pr[i]);
		dist[0] = 0.0;
		dist[n] = reach;
		
		printf("Data Set #%d\nminimum cost = $%.2lf\n", cont++, cus + ((backtrack(0, cap))/100.00));
	}
	return 0;
}
double backtrack(int i, double c)
{
	if(i == n)
		return 0;
		
	if(((dist[i+1] - dist[i])/miles) > c) //|| ((reach - dist[i])/miles) > c)//tenho que abastecer
		return 200.00 + ((cap-c)*pr[i]) + backtrack(i+1, cap - ((dist[i+1] - dist[i])/miles));
		
	if(c > (cap/2))//nao posso abastecer
		return backtrack(i+1, c - ((dist[i+1] - dist[i])/miles));
		
	//posso fazer os dois
	return min(200.00 + ((cap-c)*pr[i]) + backtrack(i+1, cap - ((dist[i+1] - dist[i])/miles)),
				backtrack(i+1, c - ((dist[i+1] - dist[i])/miles)));
}
