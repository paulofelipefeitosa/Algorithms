#include <bits/stdc++.h>
using namespace std;
struct edge
{
	int v, st, du;
};
vector<edge>graph[10001];
bool marq[10001] = {};
int backtrack(int num, int time);
int main()
{
	int n, cont = 1;
	int ele[205], pt;
	scanf("%d", &n);
	printf("CALL FORWARDING OUTPUT\n");
	while(n--)
	{
		int v1, v2, ini, te;
		pt = 0;
		while(scanf("%d", &v1), v1)
		{
			scanf("%d %d %d", &ini, &te, &v2);
			graph[v1].push_back((edge){v2, ini, te});
			ele[pt++] = v1;
			ele[pt++] = v2;
		}
		printf("SYSTEM %d\n", cont++);
		int cal, num;
		while(scanf("%d", &cal), cal != 9000)
		{
			scanf("%d", &num);
			marq[num] = true;
			int bak = backtrack(num, cal);
			printf("AT %04d CALL TO %04d RINGS %04d\n", cal, num, bak);
			for(int i = 0;i < pt;i++)
				marq[ele[i]] = false;
		}
		for(int i = 1;i < 10000;i++)
			graph[i].clear();
	}
	printf("END OF OUTPUT\n");
	return 0;
}
int backtrack(int num, int time)
{
	marq[num] = true;
	for(int i = 0;i < (int)graph[num].size();i++)
		if(time >= graph[num][i].st && time <= (graph[num][i].st + graph[num][i].du))
		{
			if(marq[graph[num][i].v])
				return 9999;
			else
				return backtrack(graph[num][i].v, time);
		}
	return num;
}
