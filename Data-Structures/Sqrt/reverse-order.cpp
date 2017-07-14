#include <bits/stdc++.h>
#define MAX  100005
#define MAXS 1005
using namespace std;
int n, s;
int arr[MAX], aux[MAX], pos[MAX];
int qele[MAXS] = {}, qri[MAXS], qrj[MAXS];
vector<pair<int,int> >group;

void build();
void update(int l, int r);
int split(int *gp, int l, int r);
int gfind(int *j, int *qnt, int *k, char side);
int main()
{
	pair<int,int>aa[MAX];
	while(scanf("%d", &n), n)
	{
		s = sqrt(n);
		if(s*s < n)
			s++;
		for(int i = 0;i < n;i++)
		{
			int num;
			scanf("%d", &num);
			aa[i] = make_pair(num, i);
		}
		sort(aa, aa+n);
		for(int i = 0;i < n;i++)
		{
			pos[i+1] = aa[i].second;
			arr[aa[i].second] = i+1;
		}
		group.push_back(make_pair(0, n-1));
		qele[0] = n;
		
		int q = 0;
		bool f = false;
		for(int i = 0;i < n;i++)
		{
			int p = pos[i+1];
			for(int j = 0;j < q;j++)
				if(p >= qri[j] && p <= qrj[j])
					p = qrj[j] + qri[j] - p;
			if(!f)
			{
				printf("%d", p+1);
				f = true;
			}
			else
				printf(" %d", p+1);
			update(i, p);
			qri[q] = i; qrj[q++] = p;
			if(group.size() > s || q > s)
			{
				q = 0;
				build();
			}
		}
		putchar('\n');
		group.clear();
	}
	return 0;
}
void update(int l, int r)
{
	int qntl = 0, qntr = 0, ll, rr;
	int gpl = gfind(&l, &qntl, &rr, 0), gpr = gfind(&r, &qntr, &ll, 1);
	if(gpl == gpr)
	{
		split(&gpl, l, r);
		swap(group[gpl].first, group[gpl].second);
	}
	else
	{
		gpr += split(&gpl, l, rr);//mudança no r
		split(&gpr, ll, r);
		
		reverse(group.begin()+gpl, group.begin()+gpr+1);
		reverse(qele+gpl, qele+gpr+1);
		for(int i = gpl;i <= gpr;i++)
			swap(group[i].first, group[i].second);
	}
}
int split(int *gp, int l, int r)
{
	int cont = 0;
	if(group[*gp].first > group[*gp].second)
	{
		group.insert(group.begin()+*gp+1, make_pair(l, r));
		group.insert(group.begin()+*gp+2, make_pair(r-1, group[*gp].second));
		group[*gp].second = l+1;
		if(group[*gp].first < group[*gp].second)
			group.erase(group.begin()+*gp);
		else
			*gp = *gp + 1, cont = 1;
		if(group[*gp+1].first < group[*gp+1].second)
			group.erase(group.begin()+*gp+1);
	}
	else
	{
		group.insert(group.begin()+*gp+1, make_pair(l, r));
		group.insert(group.begin()+*gp+2, make_pair(r+1, group[*gp].second));
		group[*gp].second = l-1;
		if(group[*gp].first > group[*gp].second)
			group.erase(group.begin()+*gp);
		else
			*gp = *gp + 1, cont = 1;
		if(group[*gp+1].first > group[*gp+1].second)
			group.erase(group.begin()+*gp+1);
	}
	for(int i = max(0, *gp-3);i < group.size();i++)
		qele[i] = abs(group[i].second - group[i].first) + 1;
	return cont;
}
void build()
{
	int k = 0;
	for(int i = 0;i < group.size();i++)
	{
		if(group[i].first < group[i].second)
		{
			for(int j = group[i].first;j <= group[i].second;j++)
				aux[k++] = arr[j];
		}
		else
		{
			for(int j = group[i].first;j >= group[i].second;j--)
				aux[k++] = arr[j];
		}
	}
	for(int i = 0;i < n;i++)
	{
		pos[aux[i]] = i;
		arr[i] = aux[i];
	}
	group.clear();
	group.push_back(make_pair(0, n-1));
	qele[0] = n;
}
int gfind(int *j, int *qnt, int *k, char side)
{
	int i = 0;
	while(*qnt + qele[i] - 1 < *j)
		*qnt += qele[i++];
	if(group[i].first > group[i].second)
		*j = group[i].first - (*j - *qnt);
	else
		*j = group[i].first + (*j - *qnt);
	if(side == 0)
		*k = group[i].second;
	else
		*k = group[i].first;
	return i;
}
