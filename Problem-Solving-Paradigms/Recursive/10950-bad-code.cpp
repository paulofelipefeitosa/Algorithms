#include <bits/stdc++.h>
using namespace std;
string str;
char ans[101];
int n, tam, cont;
pair<char, string>code[40];
bool backtrack(int i, int k);
int main()
{
	int caso = 1;
	ios_base::sync_with_stdio(false);
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
		cont = 0;
		cout<<"Case #"<<caso++<<endl;
		backtrack(0, 0);
		
		cout<<endl;
	}
	return 0;
}
bool backtrack(int i, int k)
{
	if(k == tam)
	{
		ans[i] = '\0';
		cout<<ans<<endl;
		if(++cont == 100) 
			return true;
		return false;
	}
	while(str[k] == '0')
		k++;
	for(int j = 0;j < n;j++)
	{
		int idx = k, l;
		for(l = 0;l < (int)code[j].second.size() && idx < tam;l++, idx++)
			if(code[j].second[l] != str[idx])
				break;
		
		if(l == (int)code[j].second.size())
		{
			ans[i] = code[j].first;
			if(backtrack(i+1, idx))
				return true;
		}
	}
	return false;
}
