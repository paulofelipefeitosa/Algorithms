#include <bits/stdc++.h>
using namespace std;
string str;
char ans[101];
int n, tam, cont;
vector<int>occur[101];
pair<char, string>code[40];
void build();
bool backtrack(int i, int k, bool zr);
int main()
{
	ios_base::sync_with_stdio(false);
	int caso = 1;
	while(cin>>n, n)
	{
		string aux;
		for(int i = 0;i < n;i++)
		{
			cin>>aux>>code[i].second;
			code[i].first = aux[0];
		}
		sort(code, code+n);
		cin>>str;
		tam = str.size();
		
		build();
		
		cont = 0;
		cout<<"Case #"<<caso++<<endl;
		backtrack(0, 0, true);
		
		for(int i = 0;i < tam;i++)
			occur[i].clear();
		cout<<endl;
	}
	return 0;
}
bool backtrack(int i, int k, bool zr)
{
	if(k == tam)
	{
		if(zr)
		{
			ans[i] = '\0';
			cout<<ans<<endl;
			if(++cont == 100) return true;
		}
		return false;
	}
	if(str[k] == '0')
	{
		if(backtrack(i, k+1, false)) return true;
		return false;
	}
	for(int j = 0;j < (int)occur[k].size();j++)
	{
		int idx = occur[k][j]; 
		ans[i] = code[idx].first;
		if(backtrack(i+1, k+(int)code[idx].second.size(), true))
			return true;
	}
	return false;
}
void build()
{
	vector<int>hash[10];
	for(int i = 0;i < tam;i++)
		hash[str[i]-'0'].push_back(i);
	for(int i = 0;i < n;i++)
	{
		char c = code[i].second[0] - '0';
		for(int j = 0;j < (int)hash[c].size();j++)
		{
			int pos = hash[c][j];
			bool flag = true;
			for(int k = 1;k < code[i].second.size() && flag;k++)
			{
				char aux = code[i].second[k] - '0';
				if(!binary_search(hash[aux].begin(), hash[aux].end(), pos+k))
					flag = false;
			}
			if(flag)
				occur[pos].push_back(i);
		}
	}
}
