#include <bits/stdc++.h>
using namespace std;
bool comp(char a, char b)
{
	int v1 = ((a-'A')%9) + 1;
	int v2 = ((b-'A')%9) + 1;
	if(v1 == v2)
		return a < b;
	return v1 < v2;
}
int main()
{
	char vog[7], con[27];
	int t, pt1 = 0, pt2 = 0;
	
	for(char i = 'A';i <= 'Z';i++)
		if(i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
			vog[pt1++] = i;
		else
			con[pt2++] = i;
	//vog[pt1] = con[pt2] = '\0';
	sort(vog, vog+pt1, comp);
	sort(con, con+pt2, comp);
	
	char ansV[305], ansC[305], ans[605];
	scanf("%d", &t);
	for(int k = 1;k <= t;k++)
	{
		int n, pont1 = 0, pont2 = 0, cont1 = 0, cont2 = 0, qt1 = 0, qt2 = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			if(i & 1)
			{
				ansV[qt1++] = vog[pont1];
				cont1++;
				if(cont1 == 21)
				{
					pont1++;
					cont1 = 0;
				}
			}
			else
			{
				ansC[qt2++] = con[pont2];
				cont2++;
				if(cont2 == 5)
				{
					pont2++;
					cont2 = 0;
				}
			}
		sort(ansV, ansV+qt1);
		sort(ansC, ansC+qt2);
		printf("Case %d: ", k);
		for(int i = 1, j = 0, k = 0;i <= n;i++)
			if(i & 1)
				ans[i-1] = ansV[j++];
			else
				ans[i-1] = ansC[k++];
		ans[n] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}
