#include <bits/stdc++.h>
using namespace std;
int vet[10], sol, ans, n;
bool order();
void backtrack(int cont);
int main()
{
	int cont = 1;
	while(scanf("%d", &n), n)
	{
		for(int i = 0;i < n;i++)
			scanf("%d", &vet[i]);
		ans = 1<<30;
		sol = 0;
		if(!order())
			backtrack(0);
		printf("There are %d swap maps for input data set %d.\n", sol, cont++);
	}
	return 0;
}
void backtrack(int cont)
{
	if(order())
	{
		if(cont < ans)
		{
			ans = cont;
			sol = 1;
		}
		else if(cont == ans)
			sol++;
		return;
	}
	for(int i = 1;i < n;i++)
		if(vet[i-1] > vet[i])
		{
			swap(vet[i-1], vet[i]);
			backtrack(cont+1);
			swap(vet[i-1], vet[i]);
		}
}
bool order()
{
	for(int i = 1;i < n;i++)
		if(vet[i-1] > vet[i])
			return false;
	return true;
}
