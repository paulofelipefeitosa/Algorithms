#include <bits/stdc++.h>
using namespace std;

char color[] = {'R', 'G', 'B', 'Y', 'O', 'V'};
char all[365][6], str[6];
int sol = 0, used = 0;

void generate(int pos);
bool match(char ref[], char s[], int n1, int n2);

int main()
{
	char s1[6], s2[6];
	int t, n[2][2];
	
	generate(0);
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s %d %d", s1, &n[0][0], &n[0][1]);
		scanf("%s %d %d", s2, &n[1][0], &n[1][1]);

		bool flag = false;
		for(int i = 0;i < sol && !flag;i++)
			if(match(s1, all[i], n[0][0], n[0][1]) && match(s2, all[i], n[1][0], n[1][1]))
				flag = true;
		if(flag)
			puts("Possible");
		else
			puts("Cheat");
	}
	
	return 0;
}
bool match(char ref[], char s[], int n1, int n2)
{
	int cont = 0;
	for(int i = 0;i < 4;i++)
		if(s[i] == ref[i])
			cont++;
	if(cont != n1)
		return false;
		
	int n = 4 - n1 - n2;
	
	for(int i = 0;i < 4;i++)
	{
		bool flag = false;
		for(int j = 0;j < 4 && !flag;j++)
			if(s[i] == ref[j])
				flag = true;
		if(!flag)
			n--;
	}
	
	if(n == 0)
		return true;
	else
		return false;
}
void generate(int pos)
{
	if(pos == 4)
	{
		str[pos] = '\0';
		strcpy(all[sol], str);
		sol++;
	}
	else
	{
		for(int i = 0;i < 6;i++)
		{
			if(!(used & (1<<i)))
			{
				used |= (1<<i);
				str[pos] = color[i];
				generate(pos+1);
				used &= ~(1<<i);
			}
		}
	}
}
