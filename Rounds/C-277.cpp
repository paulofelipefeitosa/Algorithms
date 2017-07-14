#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, s;
	scanf("%d %d", &m, &s);
	if(m == 1 && s == 0)
	{
		puts("0 0");
		return 0;
	}
	if(s == 0 || (m*9) < s)
	{
		puts("-1 -1");
		return 0;
	}
	char lar[105], small[105];
	for(int i = 0, aux = s;i < m;i++, aux -= 9)
		lar[i] = ((aux >= 9) ? 9 : max(aux, 0)) + '0';
	lar[m] = '\0';
	small[0] = '1';
	for(int i = m-1, aux = s - 1;i >= 0;i--, aux -= 9)
		if(i == 0)
			small[i] += ((aux >= 9) ? 9 : max(aux, 0));
		else
			small[i] = ((aux >= 9) ? 9 : max(aux, 0)) + '0';
	small[m] = '\0';
	printf("%s %s\n", small, lar);
	return 0;
}
