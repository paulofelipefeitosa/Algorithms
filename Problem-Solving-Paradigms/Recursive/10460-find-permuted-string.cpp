#include <bits/stdc++.h>
using namespace std;
char ans[30], str[30];
int used = 0, n;
void backtrack(int id, int tam);
int main()
{
	int t, id;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", str);
		scanf("%d", &id);
		n = strlen(str);
		backtrack(id, n);
	}
	return 0;
}
void backtrack(int id, int tam)
{
	if(tam == 0)
	{
		ans[n] = '\0';
		printf("%s\n", ans);
		return;
	}
	int pos = (id-1)%tam;
	for(int i = 0, ct = 0;i < n;i++)
		if(!(used & (1<<i)))
		{
			if(ct == pos)
			{
				ans[i] = str[tam-1];
				used |= (1<<i);
				backtrack((id%tam == 0) ? (id/tam) : ((id/tam) + 1), tam-1);
				used &= ~(1<<i);
				return;
			}
			ct++;
		}
}
