#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, cont = 1;
	while(cin>>n, n)
	{
		string no1, no2;
		cin>>no1>>no2;
		cout<<"Teste "<<cont<<endl;
		int n1, n2;
		for(int i = 0;i < n;i++)
		{
			cin>>n1>>n2;
			if((n1+n2)%2 == 0)
				cout<<no1<<endl;
			else
				cout<<no2<<endl;
		}
		cont++;
		cout<<endl;
	}
	
	return 0;
}
