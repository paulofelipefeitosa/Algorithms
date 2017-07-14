#include <bits/stdc++.h>
using namespace std;
int main()
{
	string palavra;
	
	cin>>palavra;
	
	string esqtodir, dirtoesq;
	
	for(int i = 0;i < (int)palavra.size();i++)
		if(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u')
			esqtodir.push_back(palavra[i]);
	
	for(int i = (int)palavra.size() - 1;i >= 0;i--)
		if(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u')
			dirtoesq.push_back(palavra[i]);
	
	if(esqtodir == dirtoesq)
		cout<<"S\n";
	else
		cout<<"N\n";
		
	return 0;
}
