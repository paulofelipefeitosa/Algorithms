#include <bits/stdc++.h>
#define MAX 100005
#define left(x) x<<1
#define right(x) x<<1|1
using namespace std;
int tree[MAX<<4], pos[MAX];
map<int, vector<int> >mapa;
int gcd(int a, int b);
void update(int i, int val);
void build(int p, int l, int r);
int main()
{
	int q, n = 0;
	scanf("%d", &q);
	getchar();
	build(1, 1, 100000);
	while(q--)
	{
		char op;
		int x;
		scanf("%c %d", &op, &x);
		getchar();
		if(op == '+')
		{
			mapa[x].push_back(++n);
			update(n, x);
			if(tree[1] == 0)
				printf("1\n");
			else
				printf("%d\n", tree[1]);
		}
		else
		{
			int p = mapa[x].back();
			mapa[x].pop_back();
			update(p, 0);
			if(tree[1] == 0)
				printf("1\n");
			else
				printf("%d\n", tree[1]);
		}
	}
	return 0;
}
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}
void build(int p, int l, int r)
{
	if(l == r)
	{
		tree[p] = 0;
		pos[l] = p;
	}
	else
	{
		build(left(p), l, (l+r)>>1);
		build(right(p), ((l+r)>>1) + 1, r);
		tree[p] = gcd(tree[left(p)], tree[right(p)]);
	}
}
void update(int i, int val)
{
	int p = pos[i];
	tree[p] = val;
	while(p>>=1)
		tree[p] = gcd(tree[left(p)], tree[right(p)]);
}
