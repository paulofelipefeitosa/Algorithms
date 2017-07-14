#include <bits/stdc++.h>
char str[30];
using namespace std;
int start, end, tam;
int main()
{
	while(scanf("%d", &start))
	{
		scanf(" %[^0123456789]s", str);
		scanf("%d", &end);
		printf("%d %s %d\n", start, str, end);
	}
	return 0;
}
