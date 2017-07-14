#include <bits/stdc++.h>
using namespace std;
map<string, bool>mapa;
string s1, s2;
bool findall(string at);
int main()
{
	string s1, s2;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		cin>>s1>>s2;
		findall(s1);
		if(mapa.find(s2)==mapa.end())
			puts("Not Equal");
		else
			puts("Equal");
		mapa.clear();
	}
	return 0;
}
bool findall(string at)
{
	if(mapa.find(at)!=mapa.end())
		return false;
	mapa[at] = true;
	if(at == s2)
		return true;
	string a(6, '0');
	//op I
	a[0] = at[4]; a[1] = at[2]; a[2] = at[0]; a[3] = at[3]; a[4] = at[1]; a[5] = at[5];
	if(findall(a)) return true;
	//op II
	a[0] = at[3]; a[1] = at[5]; a[2] = at[2]; a[3] = at[1]; a[4] = at[4]; a[5] = at[0];
	if(findall(a)) return true;
	//op III
	a[0] = at[0]; a[1] = at[1]; a[2] = at[5]; a[3] = at[2]; a[4] = at[3]; a[5] = at[4];
	if(findall(a)) return true;
}
