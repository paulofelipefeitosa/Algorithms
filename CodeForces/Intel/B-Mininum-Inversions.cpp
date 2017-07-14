#include <bits/stdc++.h>
using namespace std;
struct TRADE
{
	pair<int,int>tt[2];
	int s;
};
int n, m, table[21][21], num[21];
TRADE path;
vector<TRADE>hash[21];
bool ordered(int i);
void backtrack(int i, int t);
bool recur(int i, pair<int,int>last);
int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			scanf("%d", &table[i][j]);
			
	int maxx = 0, cnt[3] = {};
	for(int i = 0;i < n;i++)
	{
		if(!ordered(i))
		{
			num[i] = 1<<30;
			path.s = 0;
			backtrack(i, 0);
			maxx = max(maxx, num[i]);
			if(num[i] != 1<<30)
				cnt[num[i]]++;
		}
		else
		{
			num[i] = 0;
			cnt[0]++;
		}
	}
	
	if(maxx > 2)
	{
		puts("NO");
		return 0;
	}
	if(cnt[0] == n || cnt[1] == n || (cnt[0] + cnt[1]) == n)
	{
		puts("YES");
		return 0;
	}
	
	if(recur(0, pair<int,int>(0, 0)))
		puts("YES");
	else
		puts("NO");
	
	return 0;
}
bool recur(int i, pair<int,int>last)
{
	if(i == n)
		return true;
	if(num[i] == 0)
		return recur(i+1, last);
		
	pair<int,int>pp = pair<int,int>(0, 0);
	for(int j = 0;j < (int)hash[i].size();j++)
		for(int k = 0;k < hash[i][j].s;k++)
		{
			if(last == pp)
			{
				if(recur(i+1, hash[i][j].tt[k]))
					return true;
			}
			else if(hash[i][j].tt[k] == last)
			{
				if(recur(i+1, last))
					return true;
			}
			
		}
	return false;
}
void backtrack(int i, int t)
{
	if(ordered(i))
	{
		num[i] = min(num[i], t);
		hash[i].push_back(path);
		return;
	}
	if(t == 2)
		return;
	for(int j = 0;j < m;j++)
		for(int k = j+1;k < m;k++)
		{
			swap(table[i][j], table[i][k]);
			path.tt[t] = pair<int,int>(j, k);
			path.s++;
			backtrack(i, t+1);
			path.s--;
			swap(table[i][j], table[i][k]);
		}
}
bool ordered(int i)
{
	for(int j = 1;j < m;j++)
		if(table[i][j-1] > table[i][j])
			return false;
	return true;
}
