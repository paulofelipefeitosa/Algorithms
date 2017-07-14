#include <bits/stdc++.h>
#define MAX 100005
#define MAXS 320
using namespace std;
struct cttt
{
	int c1, c2, c3;
};
cttt rank[MAX];
int qx[MAX], ql1[MAX], ql2[MAX];
bool comp(cttt a, cttt b);
bool comp1(int a, int b);
bool comp2(int a, int b);
bool comp3(int a, int b);
bool comp4(int a, int b);
int main()
{
	int p1[MAX], p2[MAX], pos1[MAX], pos2[MAX];
	vector<int>group[MAXS];
	set<int>cur;
	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d %d", &rank[i].c1, &rank[i].c2, &rank[i].c3);
			p1[i] = p2[i] = i;
		}
		sort(rank, rank+n, comp);
		sort(p1, p1+n, comp1);
		sort(p2, p2+n, comp2);
		
		for(int i = 0;i < n;i++)
			pos1[p1[i]] = pos2[p2[i]] = i;

		int s = sqrt(n);
		if(s*s < n)
			s++;
		for(int i = n-1;i > 0;i--)
		{
			//query[0, i-1], [0, pos1[i]-1], [0, pos2[i]-1]
			qx[i] = i-1; ql1[i] = pos1[i]-1; ql2[i] = pos2[i]-1;
			group[ql1[i]/s].push_back(i);
		}
		for(int i = 0;i < s;i++)
			if(i & 1)
				sort(group[i].begin(), group[i].end(), comp4);
			else
				sort(group[i].begin(), group[i].end(), comp3);
				
		vector<bool>occ1(n+2, false), occ2(n+2, false);
		int pt1 = 0, pt2 = 0, cont = n;
		
		for(int i = 0;i < s;i++)
		{
			for(int j = 0;j < group[i].size();j++)
			{
				int k = group[i][j];
				
				if(ql1[k] < 0 || ql2[k] < 0)
					continue;
				
				while(pt1 < ql1[k])//p1
				{
					if(occ2[p1[pt1]])
						//cur.insert(p1[pt1]);
					occ2[p1[pt1]] = true;
					pt1++;
				}
				while(pt1 > ql1[k])
				{
					if(occ2[p1[pt1]])
						//cur.erase(p1[pt1]);
					occ1[p1[pt1]] = false;
					pt1--;
				}
				while(pt2 < ql2[k])//p2
				{
					if(occ1[p2[pt2]])
						//cur.insert(p2[pt2]);
					occ2[p2[pt2]] = true;
					pt2++;
				}
				while(pt2 > ql2[k])
				{
					if(occ1[p2[pt2]])
						//cur.erase(p2[pt2]);
					occ2[p2[pt2]] = false;
					pt2--;
				}
				
				if(!cur.empty() && *cur.begin() <= qx[k])
					cont--;
			}
			group[i].clear();
		}
		printf("%d\n", cont);
		cur.clear();
	}
	return 0;
}
bool comp(cttt a, cttt b)
{
	if(a.c1 == b.c1)
	{
		if(a.c2 == b.c2)
			return a.c3 < b.c3;
		return a.c2 < b.c2;
	}
	return a.c1 < b.c1;
}
bool comp1(int a, int b)
{
	return rank[a].c2 < rank[b].c2;
}
bool comp2(int a, int b)
{
	return rank[a].c3 < rank[b].c3;
}
bool comp3(int a, int b)
{
	return ql2[a] < ql2[b];
}
bool comp4(int a, int b)
{
	return ql2[a] > ql2[b];
}
