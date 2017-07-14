#include <bits/stdc++.h>
#define TAB_SIZE 8
using namespace std;

int path[TAB_SIZE];
int possibles[100][TAB_SIZE];
int solutions, used, diag_esq, diag_dir;

void backtrack(int queen_num);

int main()
{
	int caso = 1;
	solutions = used = diag_dir = diag_esq = 0;
	backtrack(0);
	
	int config[TAB_SIZE];
	while(scanf("%d", &config[0])!=EOF)
	{
		int minn = 1<<30, sum;
		config[0]--;
		for(int i = 1;i < TAB_SIZE;i++)
			scanf("%d", &config[i]), config[i]--;
		for(int i = 0;i < solutions;i++)
		{
			sum = 0;
			for(int j = 0;j < TAB_SIZE;j++)
				if(possibles[i][j] != config[j])
					sum++;
			minn = min(minn, sum);
		}
		printf("Case %d: %d\n", caso++, minn);
	}
	return 0;
}
void backtrack(int queen_num)
{
	if(queen_num == TAB_SIZE)
	{
		for(int i = 0;i < TAB_SIZE;i++)
			possibles[solutions][i] = path[i];
		solutions++;
		return;
	}
	for(int i = 0;i < TAB_SIZE;i++)
	{
		if(!(used & (1<<i)) && !(diag_dir & (1<<(i + queen_num))) && !(diag_esq & (1<<(i - queen_num + 7))))
		{
			used |= (1<<i);
			diag_dir |= (1<<(i + queen_num));
			diag_esq |= (1<<(i - queen_num + 7));
			path[queen_num] = i;

			backtrack(queen_num + 1);

			used &= ~(1<<i);
			diag_dir &= ~(1<<(i + queen_num));
			diag_esq &= ~(1<<(i - queen_num + 7));
		}
	}
}
