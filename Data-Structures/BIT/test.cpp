#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 250, m = 250;
	long long int cont = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			for(int k = i;k <= n;k++)
				for(int l = j;l <= m;l++)
					cont++;
	cout<<cont<<endl;
	return 0;
}
