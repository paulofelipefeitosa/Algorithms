#include <bits/stdc++.h>
#define geti(a) scanf("%d", &a)
#define getii(a, b) scanf("%d %d", &a, &b)
#define getiii(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pf printf
#define sc scanf
#define rep(a, b, x) for(int x = a;x < b;x++)
#define reu(a, b, x) for(int x = a;x <= b;x++)
#define pi pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define pq priority_queue
using namespace std;
int main()
{
	string s;
	cin>>s;
	char aux = 'a';
	int cont = 0;
	for(int i = 0;i < s.size();i++)
	{
		int dif1 = abs(aux - s[i]);
		int dif2 = 26 - dif1;
		cont += min(dif1, dif2);
		aux = s[i];
	}
	printf("%d\n", cont);
	return 0;
}
