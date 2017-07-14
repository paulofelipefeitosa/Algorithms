#include <bits/stdc++.h>
using namespace std;
int id, n, state, ans, used;
bool backtrack(int i);
int main()
{
	char st[35];
	while(scanf("%d %d %s", &id, &n, st)!=EOF)
	{
		used = ans = state = 0;
		for(int i = 0;i < n;i++)
			if(st[i] == '1')
				state |= (1<<(n-i-1));
				
		if(backtrack(0))
			puts("REACHABLE");
		else
			puts("GARDEN OF EDEN");
	}
	return 0;
}
bool backtrack(int i)
{
	if(n == i) return true;
	
	for(int k = 0;k < 8;k++)
	{
		if(((state & (1<<i)) && 1) == ((id & (1<<k)) && 1))
		{
			int pos[] = {(i+1)%n, i, (i-1+n)%n};//L C R
			int ch[3], it[3], pt = 0;
			
			bool flag = true;
			for(int j = 0;j < 3 && flag;j++)
			{
				if((used & (1<<pos[j])))
				{
					if(((k & (1<<(2-j))) && 1) != ((ans & (1<<pos[j])) && 1))
						flag = false;
				}
				else
				{
					ch[pt] = pos[j];
					it[pt++] = j;
				}
			}
			
			if(flag)
			{
				for(int j = 0;j < pt;j++)
				{
					used |= (1<<ch[j]);
					if(k & (1<<(2-it[j])))
						ans |= (1<<ch[j]);
					else
						ans &= ~(1<<ch[j]);
				}
				if(backtrack(i+1))
					return true;
				for(int j = 0;j < pt;j++)
					used &= ~(1<<ch[j]);
			}
		}
	}
	return false;
}
