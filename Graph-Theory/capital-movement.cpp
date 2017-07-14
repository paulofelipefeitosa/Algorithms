#include <bits/stdc++.h>
#define MAX 50005
#define left(x) (x<<1)
#define right(x) (x<<1|1)
using namespace std;
int pop[MAX], ar[MAX];
int info[4][MAX], pai[MAX];
int tree[MAX<<2];
vector<int>graph[MAX];
void bfs(int v, int n);
int build(int p, int l, int r);
int query(int p, int l, int r, int ql, int qr);
void solve(int *val, int *ans, int ql, int qr, int n);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			scanf("%d", &pop[i]);
		for(int i = 1;i < n;i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		bfs(1, n);
		/*for(int i = 1;i <= n;i++)
			printf("%d ", ar[i]);
		puts("");
		/*for(int i = 1;i <= n;i++)
			printf("%d %d %d %d\n", info[0][i], info[1][i], info[2][i], info[3][i]);*/
		build(1, 1, n);
		bool flag = false;
		for(int i = 1;i <= n;i++)
		{
			int val = 0, ans = -1;
			solve(&val, &ans, 1, info[1][i] - 1, n);
			solve(&val, &ans, info[1][i] + 1, info[0][i] - 1, n);
			solve(&val, &ans, info[0][i] + 1, info[2][i], n);
			solve(&val, &ans, info[3][i] + 1, n, n);
			if(flag)
				putchar(' ');
			printf("%d", ans);
			flag = true;
		}
		puts("");
		for(int i = 1;i <= n;i++)
			graph[i].clear();
	}
	return 0;
}
void solve(int *val, int *ans, int ql, int qr, int n)
{
	//printf("[%d, %d]\t", ql, qr);
	if(ql > qr || qr > n || ql > n)
		return;
	int qq = query(1, 1, n, ql, qr);
	if(qq != -1)
		if(pop[qq] > *val)
		{
			*ans = qq;
			*val = pop[qq];
		}
	return;
}
int build(int p, int l, int r)
{
	if(l == r)
		tree[p] = ar[l];
	else
	{
		build(left(p), l, (l+r)>>1);
		build(right(p), ((l+r)>>1) + 1, r);
		tree[p] = ((pop[tree[left(p)]] > pop[tree[right(p)]]) ? tree[left(p)] : tree[right(p)]);
	}
}
int query(int p, int l, int r, int ql, int qr)
{
	if(l > qr || r < ql)
		return -1;
	if(l >= ql && r <= qr)
		return tree[p];
	int esq = query(left(p), l, (l+r)>>1, ql, qr);
	int dir = query(right(p), ((l+r)>>1) + 1, r, ql, qr);
	if(esq == -1)
		return dir;
	if(dir == -1)
		return esq;
	return ((pop[esq] > pop[dir]) ? esq : dir);
}
void bfs(int v, int n)
{
	queue<int>fila;
	vector<bool>marq(n+1, false);

	int count = 1;
	fila.push(v);
	marq[v] = true;

	pai[v] = v;

	info[0][v] = count;
	ar[count] = v;

	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();
		info[1][v] = info[0][pai[v]];
		info[2][v] = count;
		for(int u : graph[v])
			if(!marq[u])
			{
				marq[u] = true;
				pai[u] = v;
				fila.push(u);

				info[0][u] = ++count;
				ar[count] = u;
			}
		info[3][v] = count;
	}
}