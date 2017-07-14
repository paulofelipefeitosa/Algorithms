#include <bits/stdc++.h>
using namespace std;
struct STU
{
	int scr, id;
};
bool comp(STU a, STU b)
{
	if(a.scr == b.scr)
		return a.id < b.id;
	return a.scr > b.scr;
}
int vag[1005], ans[1005], n, m;
STU stu[1005];
vector<int>cur[1005];
void process(int i, int j, int tam);
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m;i++)
		scanf("%d", &vag[i]);
	int qt, num;
	for(int i = 0;i < n;i++)
	{
		scanf("%d %d", &stu[i].scr, &qt);
		stu[i].id = i;
		for(int j = 0;j < qt;j++)
		{
			scanf("%d", &num);
			cur[i].push_back(num);
		}
		ans[i] = -1;
	}
	sort(stu, stu+n, comp);
	for(int i = 0, k = 0;i < n;i++)
	{
		int mx = (int)cur[i].size();
		k = i;
		
		for(;k < (n-1);k++)
		{
			if(stu[i].scr == stu[k+1].scr)
				mx = max(mx, (int)cur[k+1].size());
			else
				break;
		}
		
		if(i == k)
		{
			for(int j = 0;j < cur[stu[i].id].size();j++)
				if(vag[cur[stu[i].id][j]])
				{
					ans[stu[i].id] = cur[stu[i].id][j];
					vag[cur[stu[i].id][j]]--;
					break;
				}
		}
		else
		{
			//printf("%d %d %d\n", i, k, mx);
			process(i, k, mx);
			i = k;
		}
	}
	for(int i = 0;i < n;i++)
		printf("%d\n", ans[i]);
	return 0;
}
void process(int i, int j, int tam)
{
	for(int l = 0;l < tam;l++)
	{
		for(int k = i;k <= j;k++)
		{
			if(ans[stu[k].id] == -1 && cur[stu[k].id].size() > l)
			{
				//printf("%d\n", cur[stu[k].id][l]);
				if(vag[cur[stu[k].id][l]])
				{
					ans[stu[k].id] = cur[stu[k].id][l];
					vag[cur[stu[k].id][l]]--;
				}
			}
		}
	}
}
