#include <bits/stdc++.h>
using namespace std;
string top[16];
map<string, int>id;
int bit[16], ans[16], n, sz;
bool comp(string a, string b);
void backtrack(int cont, int last, int used);
int main()
{
	ios_base::sync_with_stdio(false);
	int t, cont = 1;
	cin>>t;
	while(t--)
	{
		int c;
		cin>>n>>c>>sz;
		for(int i = 0;i < n;i++)
		{
			cin>>top[i];
			for(int j = 0;j < (int)top[i].size();j++)
				if(top[i][j] != '-')
					top[i][j] = toupper(top[i][j]);
			bit[i] = (1<<i);
		}
		sort(top, top+n, comp);
		for(int i = 0;i < n;i++)
			id[top[i]] = i;
		
		string t1, t2;
		int v1, v2;
		while(c--)
		{
			cin>>t1>>t2;
			for(int j = 0;j < (int)t1.size();j++)
				if(t1[j] != '-')
					t1[j] = toupper(t1[j]);
			for(int j = 0;j < (int)t2.size();j++)
				if(t2[j] != '-')
					t2[j] = toupper(t2[j]);
					
			v1 = id[t1];
			v2 = id[t2];
			bit[v1] |= (1<<v2);
			bit[v2] |= (1<<v1);
		}
		cout<<"Set "<<cont++<<":"<<endl;
		backtrack(0, 0, 0);
		cout<<endl;
		
		id.clear();
	}
	return 0;
}
void backtrack(int cont, int last, int used)//be careful with overlap in bitwise operations
{
	if(cont == sz)
	{
		cout<<top[ans[0]];
		for(int i = 1;i < cont;i++)
			cout<<" "<<top[ans[i]];
		cout<<endl;
		return;
	}
	for(int i = last;i < n;i++)
		if(!(used & (1<<i)))
		{
			ans[cont] = i;
			backtrack(cont+1, i+1, used | bit[i]);
		}
}
bool comp(string a, string b)
{
	if((int)a.size() == (int)b.size())
		return a < b;
	return (int)a.size() > (int)b.size();
}
