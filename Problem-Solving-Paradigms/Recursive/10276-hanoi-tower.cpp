#include <bits/stdc++.h>
using namespace std;
int peg[55], ans, n;
void backtrack(int val, int emp);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			peg[i] = -1;
		ans = 0;
		backtrack(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
void backtrack(int val, int emp)
{
	int id;
	bool fi = false;
	for(int i = 0;i < n && !fi;i++)
		if(peg[i] != -1)
		{
			int rt = (int)sqrt(peg[i]+val);
			if(rt*rt == (peg[i]+val))
			{
				fi = true;
				id = i;
			}
		}
	if(fi)
	{
		ans++;
		peg[id] = val;
		backtrack(val+1, emp);
	}
	else if(emp < n)
	{
		ans++;
		peg[emp] = val;
		backtrack(val+1, emp+1);
	}
}
