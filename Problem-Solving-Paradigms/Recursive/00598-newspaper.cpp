#include <bits/stdc++.h>
using namespace std;
string name[15];
vector<vector<int> >ans[15];
vector<int>id;
int n, a, b, used = 0;
void backtrack(int cont, int k);
int main()
{
	ios_base::sync_with_stdio(false);
	string s1, s2;
	stringstream ss;
	int t;
	cin>>t;
	cin.get(); cin.get();
	while(t--)
	{
		getline(cin, s1);
		n = 0;
		while(getline(cin, s2) && !s2.empty())
			name[n++] = s2;
		
		if(s1 == "*")
		{
			a = 1;
			b = n;
		}
		else
		{
			int num[2], id = 0;
			ss << s1;
			while(ss >> num[id++]);
			if(id == 2)
				a = b = num[0];
			else
			{
				a = num[0];
				b = num[1];
			}
			ss.clear();
		}
		
		backtrack(0, 0);
		
		for(int i = a;i <= b;i++)
		{
			cout<<"Size "<<i<<endl;
			for(int j = 0;j < (int)ans[i].size();j++)
			{
				cout<<name[ans[i][j][0]];
				for(int k = 1;k < i;k++)
					cout<<", "<<name[ans[i][j][k]];
				cout<<endl;
				ans[i][j].clear();
			}
			cout<<endl;
			ans[i].clear();
		}
		
		if(t)
			cout<<endl;
	}
	return 0;
}
void backtrack(int cont, int k)
{
	if(cont >= a && cont <= b)
	{
		ans[cont].push_back(id);
		if(cont == b)
			return;
	}
	for(int i = k;i < n;i++)
		if(!(used & (1<<i)))
		{
			used |= (1<<i);
			id.push_back(i);
			backtrack(cont+1, i+1);
			id.pop_back();
			used &= ~(1<<i);
		}
}
