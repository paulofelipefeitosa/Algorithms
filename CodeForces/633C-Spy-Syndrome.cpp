#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char str[10005];
	scanf("%d", &n);
	scanf("%s", str);
	int m;
	scanf("%d", &m);
	string sub[m];
	for(int i = 0;i < m;i++)
		cin>>sub[i];
	vector<int>hash[26];
	for(int i = 0;i < n;i++)
		hash[str[i]-'a'].push_back(i);
	
	return 0;
}
