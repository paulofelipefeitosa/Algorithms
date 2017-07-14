#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
int main()
{
	int m;
	char str[100005], ans[100005];
	bool used[30][100005] = {};
	vector<int>hash[30];
	
	scanf("%d", &m);
	scanf("%s", str);
	
	int tam = strlen(str);
	
	for(int i = 1;i <= tam;i++)
		hash[str[i-1]-'a'].push_back(i);
	
	int req = m, pt = 0, maxx = 0;
	
	while(req <= tam)
	{
		for(int i = 0;i < 26;i++)
		{	
			if(hash[i].empty() || hash[i][0] > req)
				continue;
				
			int lb = lower_bound(hash[i].begin(), hash[i].end(), req) - hash[i].begin();
			
			if(lb == hash[i].size())
				lb--;
				
			if(hash[i][lb] > req)
				lb--;
				
			if(hash[i][lb] + m >= req && !used[i][lb])
			{
				req = hash[i][lb] + m;
				used[i][lb] = true;
				ans[pt++] = i+'a';
				maxx = max(maxx, i);
				break;
			}
		}
	}
	
	for(int i = 0;i < maxx;i++)
		for(int j = 0;j < (int)hash[i].size();j++)
			if(!used[i][j])
				ans[pt++] = i+'a';
	
	sort(ans, ans+pt);
	ans[pt] = '\0';
	printf("%s\n", ans);
	
	return 0;
}
