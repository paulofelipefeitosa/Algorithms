#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int n = 50, m = 50;
	printf("%d %d\n", n, m);
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			char c = rand()%26 + 'a';
			putchar(c);
		}
		putchar('\n');
	}
	int q = 20;
	char str[60];
	printf("%d\n", q);
	for(int i = 0;i < q;i++)
	{
		int size = rand()%5 + 1;
		for(int j = 0;j < size;j++)
			str[j] = rand()%26 + 'a';
		str[size] = '\0';
		printf("%s\n", str);
	}
	return 0;
}
