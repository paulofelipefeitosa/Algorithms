#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k, pt = 0;
	char str[20];
	scanf("%d", &k);
	while(k--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int>S[m];
		set<int>conj;
		
		for(int i = 0;i < m;i++)
		{
			int num, cont = 0;
			do
			{
				scanf("%d", &num);
				S[i].push_back(num);
				conj.insert(num);
				if(++cont == 3)
					break;
			}while(getchar_unlocked() == ' ');
		}
		
		vector<int>U(conj.begin(), conj.end());
		vector<int>Si[m];
		for(int i = 0;i < m;i++)
			for(int j = 0;j < (int)S[i].size();j++)
			{
				int pos = lower_bound(U.begin(), U.end(), S[i][j]) - U.begin();
				Si[i].push_back(pos);
			}
		int tam = 1<<n;
		bool sol = false;
		for(int subset = 0;subset < tam && !sol;subset++)
		{
			bool flag = true;
			for(int i = 0;i < m && flag;i++)
			{
				if(Si[i].size() == 1)
					continue;
				int contr = 0, contb = 0;
				for(int j = 0;j < Si[i].size();j++)
				{
					if(subset & (1<<Si[i][j]))
						contr++;
					else
						contb++;
				}
				if(!(contr && contb))
					flag = false;
			}
			if(flag)
				sol = true;
		}
		if(sol)
			str[pt++] = 'Y';
		else
			str[pt++] = 'N';
	}
	str[pt] = '\0';
	printf("%s\n", str);
	return 0;
}
