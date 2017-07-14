#include <stdio.h>
#include <iostream>
#define TAB_SIZE 8
using namespace std;

int tabu[TAB_SIZE][TAB_SIZE];
int path[TAB_SIZE];
pair<int,int>possibles[100][TAB_SIZE];
int solutions = 0, used, diag_esq, diag_dir;

void backtrack(int queen_num);

int main()
{
	int k;
	scanf("%d", &k);

	used = diag_dir = diag_esq = 0;
	backtrack(0);

	while(k--)
	{
		int maxx = 0;
		for(int i = 0;i < TAB_SIZE;i++)
			for(int j = 0;j < TAB_SIZE;j++)
				scanf("%d", &tabu[i][j]);
		for(int i = 0;i < solutions;i++)
		{
			int sum = 0;
			for(int j = 0;j < TAB_SIZE;j++)
				sum += tabu[possibles[i][j].first][possibles[i][j].second];
			maxx = max(maxx, sum);
		}
		printf("%d\n", maxx);
	}
	return 0;
}
void backtrack(int queen_num)
{
	if(queen_num == TAB_SIZE)
	{
		for(int i = 0;i < TAB_SIZE;i++)
			possibles[solutions][i] = pair<int,int>(path[i], i);
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