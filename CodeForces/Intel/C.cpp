#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long int w;
	pair<int, int>ival;
};
struct comp
{
	bool operator()(node a, node b)
	{
		return a.w < b.w;
	}
};
int main()
{
	priority_queue<node, vector<node>, comp>fila;
	int n, num;
	long long int sum[100005];
	sum[0] = 0;
	
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &num);
		sum[i] = sum[i-1] + (long long int)num;
	}
	
	set<pair<int,int> >seg;
	seg.insert(pair<int,int>(1, n));
	fila.push((node){sum[n], pair<int,int>(1, n)});
	
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &num);
		auto it = seg.lower_bound(pair<int,int>(num, 0));
		pair<int,int>act;
		
		if(it == seg.end())
			act = *(--it);
		if(num < (*it).first || num > (*it).second)
			act = *(--it);
		else
			act = *it;
		
		seg.erase(it);
		if(num-1 >= act.first)
		{
			seg.insert(pair<int,int>(act.first, num-1));
			fila.push((node){sum[num-1]-sum[act.first-1], pair<int,int>(act.first, num-1)});
		}
		if(num+1 <= act.second)
		{
			seg.insert(pair<int,int>(num+1, act.second));
			fila.push((node){sum[act.second]-sum[num], pair<int,int>(num+1, act.second)});
		}
		
		node ans;
		bool flag = false;
		while(!fila.empty() && !flag)
		{
			ans = fila.top();
			if(seg.find(ans.ival) == seg.end())
				fila.pop();
			else
				flag = true;
		}
		if(flag)
			cout<<ans.w<<endl;
		else
			printf("0\n");
	}
	return 0;
}
