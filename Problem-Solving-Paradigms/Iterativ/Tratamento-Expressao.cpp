#include <bits/stdc++.h>
#define MAXS 105
#define MAX 256
using namespace std;
char str[MAXS];
int tam;
bool express(int mask);
int main()
{
	bool sol;
	while(scanf("%s", str), str[0]!='0')
	{
		sol = true;
		tam = strlen(str);
		for(int i=0;i<32 && sol;i++)
			sol = express(i);
		if(sol)
			puts("tautology");
		else
			puts("not");
	}
	return 0;
}
bool express(int mask)
{
	vector<int>stk;
	int cur, ant;
	for(int i=tam-1;i>=0;i--)
	{
		if(str[i]>='A' && str[i]<='K')
		{
			ant = stk.back(); stk.pop_back();
			cur = stk.back(); stk.pop_back();
			
			if(str[i]=='K') stk.push_back((ant && cur) ? 1 : 0);
			
			else if(str[i]=='A') stk.push_back((ant || cur) ? 1 : 0);
			
			else if(str[i]=='E') stk.push_back(((ant && cur) || (!ant && !cur)) ? 1 : 0);
			
			else stk.push_back((ant && !cur) ? 0 : 1);
		}
		else if(str[i]=='N')
		{
			cur = stk.back(); stk.pop_back();
			cur = !cur;       stk.push_back(cur);
		}
		else
			stk.push_back(mask & (1<<(str[i]-'p')));
	}
	return (stk.back()) ? true : false;
}
