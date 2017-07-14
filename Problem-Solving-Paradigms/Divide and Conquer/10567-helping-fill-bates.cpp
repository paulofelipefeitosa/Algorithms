#include <bits/stdc++.h>
#define MAXC 256
using namespace std;
vector<int>qnt[MAXC];
vector<int>::iterator it;
int main()
{
	ios_base::sync_with_stdio(false);
	string str, sq;
	int q, last, posmin, posmax;
	
	cin>>str;
	for(int i=0;i<str.size();i++)
		qnt[str[i]].push_back(i);
	
	cin>>q;
	while(q--)
	{
		cin>>sq;
		last = -1; posmin = 1<<30; posmax = 0;
		bool solve = true;
		for(int i=0;i<sq.size() && solve;i++)
		{
			it = upper_bound(qnt[sq[i]].begin(), qnt[sq[i]].end(), last);
			if(it == qnt[sq[i]].end())
				solve = false;
			else
			{
				last = *it;
				posmin = min(posmin, last);
				posmax = max(posmax, last);
			}
		}
		if(!solve)
			cout<<"Not matched"<<endl;
		else
			cout<<"Matched "<<posmin<<" "<<posmax<<endl;
	}
	return 0;
}
