#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num, n;
	set<int>y;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &num);
		y.insert(num);
	}
	bool flag = true;
	while(flag)
	{
		auto it = y.end();
		int x = *(--it);
		int s = x;
		flag = false;
		while(x>>=1)
		{
			if(y.find(x) == y.end())
			{
				y.erase(s);
				y.insert(x);
				flag = true;
				break;
			}
		}
	}
	for(auto it = y.begin();it != y.end();it++)
		printf("%d ", *it);
	putchar('\n');
	return 0;
}
