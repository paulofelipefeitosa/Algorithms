#include <bits/stdc++.h>
#define pi pair<int,int>
#define INF 1000000000000000
using namespace std;
struct laser
{
	pi st, end, dir;
};
int main()
{
	int n, m, k;
	vector<int>esq[200005];
	vector<int>dir[200005];
	int x[100005], y[100005];
	long long int ans[100005], sec = 0;
	
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0;i < k;i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		esq[x[i]-y[i]+m].push_back(i);
		dir[x[i]+y[i]].push_back(i);
		ans[i] = INF;
	}
	
	laser it, nw;
	it = (laser){pi(0, 0), pi(min(n, m), min(n, m)), pi(1, 1)};
	
	while(1)
	{
		if(it.dir.first*it.dir.second == 1)//Esquerda
		{
			int id = it.st.first - it.st.second + m;
			for(int i = 0;i < (int)esq[id].size();i++)
			{
				int j = esq[id][i];//it.st to (x, y)
				ans[j] = min(ans[j], sec + abs(x[j] - it.st.first));
			}
		}
		else if(it.dir.first*it.dir.second == -1)//Direita
		{
			int id = it.st.first + it.st.second;
			for(int i = 0;i < (int)dir[id].size();i++)
			{
				int j = dir[id][i];
				ans[j] = min(ans[j], sec + abs(it.st.first - x[j]));
			}
		}
		
		sec += abs(it.st.first - it.end.first);
		
		if(it.end == pi(0, 0) || it.end == pi(n, 0) || it.end == pi(0, m) || it.end == pi(n, m))
			break;
				
		nw.st = it.end;
		
		if(it.end.first == n)
			nw.dir = (it.dir == pi(1, 1)) ? pi(-1, 1) : pi(-1, -1);
		else if(it.end.first == 0)
			nw.dir = (it.dir == pi(-1, 1)) ? pi(1, 1) : pi(1, -1);
		else if(it.end.second == m)
			nw.dir = (it.dir == pi(-1, 1)) ? pi(-1, -1) : pi(1, -1);
		else
			nw.dir = (it.dir == pi(-1, -1)) ? pi(-1, 1) : pi(1, 1);
		
		int dis1, dis2;
		if(nw.dir.first == -1 && nw.dir.second == -1)
		{
			dis1 = abs(nw.st.first);
			dis2 = abs(nw.st.second);
			nw.end = (dis1 < dis2) ? pi(0, nw.st.second - dis1) : pi(nw.st.first - dis2, 0);
		}
		else if(nw.dir.first == -1 && nw.dir.second == 1)
		{
			dis1 = abs(nw.st.first);
			dis2 = m - nw.st.second;
			nw.end = (dis1 < dis2) ? pi(0, nw.st.second + dis1) : pi(nw.st.first - dis2, m);
		}
		else if(nw.dir.first == 1 && nw.dir.second == -1)
		{
			dis1 = n - nw.st.first;
			dis2 = abs(nw.st.second);
			nw.end = (dis1 < dis2) ? pi(n, nw.st.second - dis1) : pi(nw.st.first + dis2, 0);
		}
		else
		{
			dis1 = n - nw.st.first;
			dis2 = m - nw.st.second;
			nw.end = (dis1 < dis2) ? pi(n, nw.st.second + dis1) : pi(nw.st.first + dis2, m);
		}
		it = nw;
	}
	
	for(int i = 0;i < k;i++)
		if(ans[i] == INF)
			puts("-1");
		else
			cout<<ans[i]<<endl;
	
	return 0;
}
