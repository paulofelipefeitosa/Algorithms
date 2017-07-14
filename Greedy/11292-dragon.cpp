#include <bits/stdc++.h>
#define MAX 20005
using namespace std;
int main()
{
	int knight[MAX], n, m, num;
	multiset<int>head;
	multiset<int>::iterator it;
	while(scanf("%d %d", &n, &m), (n || m))
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &num);
			head.insert(num);
		}
		for(int i = 0;i < m;i++)
			scanf("%d", &knight[i]);
		if(m < n)
		{
			puts("Loowater is doomed!");
			head.clear();
			continue;
		}
		sort(knight, knight+m);
		int ans = 0;
		for(int i = 0;i < m && !head.empty();i++)
		{
			it = head.lower_bound(knight[i]);
			if(it == head.end())
				it--;
			else if(it == head.begin() && *it > knight[i])
				continue;
			else if(*it > knight[i])
				it--;
			ans += knight[i];
			head.erase(it);
		}
		if(!head.empty())
		{
			puts("Loowater is doomed!");
			head.clear();
		}
		else
			printf("%d\n", ans);
	}
	return 0;
}
