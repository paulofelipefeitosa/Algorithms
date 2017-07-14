#include <bits/stdc++.h>
#define MAX 500005
#define ll long long int
using namespace std;
int a[MAX], pos[MAX], pos2[MAX];
ll s[MAX];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &a[i]);
		s[i] = s[i-1] + a[i];
	}
	
	int k = 0;
	for(int i = 1;i < (n-1);i++)
		if(s[i]*3 == s[n])
			pos[k++] = i;
	
	int l = 0;
	for(int j = 2;j < n;j++)
		if(s[j]*3 == s[n]*2)
			pos2[l++] = j;
	
	sort(pos2, pos2+l);
	ll cont = 0;
	for(int i = 0;i < k;i++)
		cont += l - (upper_bound(pos2, pos2+l, pos[i]) - pos2);
	cout<<cont<<endl;
	return 0;
}
