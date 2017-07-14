#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<char, string>mapa;
	mapa['A'] = ".-";   mapa['B'] = "-..."; mapa['C'] = "-.-."; mapa['D'] = "-..";
	mapa['E'] = ".";    mapa['F'] = "..-."; mapa['G'] = "--.";  mapa['H'] = "....";
	mapa['I'] = "..";   mapa['J'] = ".---"; mapa['K'] = "-.-";  mapa['L'] = ".-..";
	mapa['M'] = "--";   mapa['N'] = "-.";   mapa['O'] = "---";  mapa['P'] = ".--.";
	mapa['Q'] = "--.-"; mapa['R'] = ".-.";  mapa['S'] = "...";  mapa['T'] = "-";
	mapa['U'] = "..-";  mapa['V'] = "...-"; mapa['W'] = ".--";  mapa['X'] = "-..-";
	mapa['Y'] = "-.--"; mapa['Z'] = "--..";
	int t;
	char code[1005], w[1005];
	vector<int>hash[256];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", code);
		int tam = strlen(code);
		for(int i = 0;i < tam;i++)
			hash[code[i]].push_back(i);
		int n, dp[tam+2], tt = tam;
		vector<pair<int,int> >oc;
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
		{
			scanf("%s", w);
			tam = strlen(w);
			string word;
			for(int j = 0;j < tam;j++)
				word += mapa[w[j]];
			tam = word.size();
			for(int j = 0;j < hash[word[0]].size();j++)
			{
				int occur = hash[word[0]][j], k = 1;
				for(int l = occur+1;k < tam;k++, l++)
					if(!binary_search(hash[word[k]].begin(), hash[word[k]].end(), l))
						break;
				if(k == tam)
					oc.push_back(pair<int,int>(occur, occur+tam));
			}
		}
		sort(oc.begin(), oc.end());
		dp[0] = 1;
		for(int i = 0;i < oc.size();i++)
			dp[oc[i].second] += dp[oc[i].first];
		printf("%d\n", dp[tt]);
		if(t)
			putchar('\n');
		hash['.'].clear();
		hash['-'].clear();
	}
	return 0;
}
