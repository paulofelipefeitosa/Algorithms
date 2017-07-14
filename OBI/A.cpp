#include <bits/stdc++.h>
using namespace std;
vector<int>graph[35];
int path[35], dgin[35], pt;
void BFS(int n);
int main()
{
	map<string, int>mapa;
	map<int, string>ret;
	int n, cont = 1;
	while(scanf("%d", &n), n)
	{
		cout<<"Teste "<<cont++<<endl;
		string str;
		for(int i = 0;i < n;i++)
		{
			cin>>str;
			mapa[str] = i;
			ret[i] = str;
			dgin[i] = 0;
		}
		int e, u, v;
		for(int i = 0;i < n;i++)
		{
			cin>>str>>e;
			u = mapa[str];
			for(int j = 0;j < e;j++)
			{
				cin>>str;
				v = mapa[str];
				graph[v].push_back(u);
				dgin[u]++;
			}
		}
		BFS(n);
		if(pt == n)
		{
			cout<<ret[path[0]];
			for(int i = 1;i < pt;i++)
				cout<<" "<<ret[path[i]];
			cout<<endl;
		}
		else
			cout<<"impossivel\n";
		cout<<endl;
		for(int i = 0;i < n;i++)
			graph[i].clear();
		mapa.clear();
		ret.clear();
	}
	return 0;
}
void BFS(int n)
{
	stack<int>pilha;
	int u, v;
	pt = 0;
	for(int i = 0;i < n;i++)
		if(dgin[i] == 0)
			pilha.push(i);
	while(!pilha.empty())
	{
		v = pilha.top();
		pilha.pop();
		path[pt++] = v;
		for(int i = 0;i < graph[v].size();i++)
		{
			u = graph[v][i];
			dgin[u]--;
			if(dgin[u] == 0)
				pilha.push(u);
		}
	}
}
