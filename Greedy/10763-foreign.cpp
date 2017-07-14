#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	map<int,int>mapa;
	while(scanf("%d", &n), n)
	{
		int a, b;
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d", &a, &b);
			mapa[a]--;
			mapa[b]++;
		}
		bool flag = true;
		for(map<int,int>::iterator it = mapa.begin();it != mapa.end() && flag;it++)
			if(it->second != 0)
				flag = false;
		if(flag)
			puts("YES");
		else
			puts("NO");
		mapa.clear();
	}
	return 0;
}
