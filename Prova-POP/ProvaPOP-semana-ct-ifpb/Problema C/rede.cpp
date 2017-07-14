#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
struct MSG
{
	int num, ini, fim;
};
struct comp
{
	bool operator()(MSG a, MSG b)
	{
		if(a.num == b.num)
			return a.ini < b.ini;
		return a.num < b.num;
	}
};
MSG msg[MAX];
int ord[10], tam[10];
int n, m;
int buffer_size(int ord[]);
int main()
{
	int cont = 1;
	scanf("%d %d", &n, &m);
	
	int minn = 1<<30;
	for(int i = 1;i <= n;i++)
	{
		ord[i] = i;
		scanf("%d", &tam[i]);
	}
	for(int i = 1;i <= m;i++)
		scanf("%d %d %d", &msg[i].num, &msg[i].ini, &msg[i].fim);
	do
	{
		minn = min(minn, buffer_size(ord));
	}while(next_permutation(ord+1, ord+n+1));
	
	printf("%d\n", minn);
	return 0;
}
int buffer_size(int ord[])
{
	set<MSG, comp>buffer;
	set<MSG, comp>::iterator it;
	int size = 0, pt = 1, exec, required = 1, end, maxx = 0;
	for(int i = 1;i <= m;i++)
	{
		exec = ord[pt];
		end = tam[exec];
		if(msg[i].num == exec && msg[i].ini == required)//execute o nó
		{
			required = msg[i].fim + 1;
			if(required >= end)//ultimo pacote
			{
				pt++;
				exec = ord[pt];
				end = tam[exec];
				required = 1;
			}
			while((it = buffer.lower_bound((MSG){exec, required, 0})) != buffer.end())//enquanto os que eu preciso estao no buffer
			{
				if((*it).num == exec && (*it).ini == required)//se existe, retire e atualize
				{
					size -= (*it).fim - (*it).ini + 1;
					required = (*it).fim+1;
					if(required >= end)
					{
						pt++;
						exec = ord[pt];
						end = tam[exec];
						required = 1;
					}
					buffer.erase(it);
				}
				else
					break;
			}
		}
		else//coloque no buffer
		{
			size += msg[i].fim - msg[i].ini + 1;
			maxx = max(maxx, size);
			buffer.insert((MSG){msg[i].num, msg[i].ini, msg[i].fim});
		}
	}
	return maxx;
}
