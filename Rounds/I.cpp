#include <bits/stdc++.h>
using namespace std;
struct task
{
	int st, ft, id;
};
task tarefa[100005], ans[100005];
int n, pt = 0;
void solve();
bool comp(task a, task b)
{
	if(a.ft == b.ft)
		return a.st < b.st;
	return a.ft < b.ft;
}
bool comp2(task a, task b)
{
	return a.st < b.st;
}
int main()
{
	int hi, mi, hf, mf;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d:%d %d:%d", &hi, &mi, &hf, &mf);
		tarefa[i].st = (hi*60)+mi;
		tarefa[i].ft = (hf*60)+mf;
		tarefa[i].id = i;
	}
	sort(tarefa, tarefa+n, comp);
	solve();
	sort(ans, ans+pt, comp2);
	for(int i = 0;i < pt;i++)
		printf("%d ", ans[i].id+1);
	putchar('\n');
	return 0;
}
void solve()
{
	int i = 0, j;
	ans[pt++] = tarefa[i];
	for(j = 1;j < n;j++)
		if(tarefa[j].st >= tarefa[i].ft)
		{
			ans[pt++] = tarefa[j];
			i = j;
		}
}
