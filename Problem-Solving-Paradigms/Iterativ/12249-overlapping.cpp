#include <bits/stdc++.h>
using namespace std;
string str[15], builded;
int vet[15];
void put(int i);
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int k = 1;k <= t;k++)
	{
		int n;
		cin>>n;
		for(int i = 0;i < n;i++)
		{
			cin>>str[i];
			vet[i] = i;
		}
		int minn = 1<<30;
		do
		{
			builded = str[vet[0]];
			for(int i = 1;i < n;i++)
				put(vet[i]);
			minn = min(minn, (int)builded.size());
		}while(next_permutation(vet, vet+n));
		cout<<"Case "<<k<<": "<<minn<<endl;
	}
	return 0;
}
void put(int i)
{
	int tam = min(builded.size(), str[i].size()), ans = 0;
	for(int p = 1;p <= tam;p++)
	{
		bool flag = true;
		for(int k = 0, l = builded.size() - p;k < p && flag;k++, l++)
			if(builded[l] != str[i][k])
				flag = false;
		if(flag)
			ans = p;
	}
	for(int j = ans;j < str[i].size();j++)
		builded.push_back(str[i][j]);
}
