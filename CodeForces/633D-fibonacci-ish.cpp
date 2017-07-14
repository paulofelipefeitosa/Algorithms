#include <bits/stdc++.h>
using namespace std;
int n, seq[1005], ans;
map<int,int>mapa;
void findseq(int i, int v, int u);
int main()
{
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &seq[i]);
		mapa[seq[i]]++;
	}
	
	sort(seq, seq+n);
	
	ans = 2;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
		{
			int sum = seq[i]+seq[j];
			if(i != j && mapa.find(sum)!=mapa.end())
			{
					mapa[seq[i]]--;
					mapa[seq[j]]--;
					findseq(2, seq[i], seq[j]);
					mapa[seq[i]]++;
					mapa[seq[j]]++;
			}
		}
	
	printf("%d\n", ans);
	return 0;
}
void findseq(int i, int v, int u)
{
	if(v == 0 && u == 0)
	{
		ans = max(ans, i+mapa[0]);
		return;
	}
	bool flag = false;
	int sum = v + u;
	if(mapa.find(sum) != mapa.end() && mapa[sum])
	{
		mapa[sum]--;
		findseq(i+1, u, sum);
		mapa[sum]++;
		flag = true;
	}
	
	if(!flag)
		ans = max(ans, i);
}
