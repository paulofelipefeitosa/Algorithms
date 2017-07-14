#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int matrix[MAX][MAX];

void kadane_2d(int row, int col);
int kadane_1d(int A[], int n, int *l, int *r);

int main()
{
	int row, col;
	scanf("%d %d", &row, &col);
	
	for(int i = 0;i < row;i++)
		for(int j = 0;j < col;j++)
			scanf("%d", &matrix[i][j]);
	
	kadane_2d(row, col);
	
	return 0;
}
void kadane_2d(int row, int col)
{
	int sum_row[row], sum_cur;
	int row_l, row_r;
	int max_sum = -(1<<30);
	int x0, x1, y0, y1;
	
	for(int left = 0;left < col;left++)
	{
		memset(sum_row, 0, sizeof(sum_row));
		for(int right = left;right < col;right++)
		{
			for(int i = 0;i < row;i++)
				sum_row[i] += matrix[i][right];
				
			sum_cur = kadane_1d(sum_row, row, &row_l, &row_r);
			
			if(sum_cur > max_sum)
			{
				max_sum = sum_cur;
				x0 = row_l;
				x1 = row_r;
				y0 = left;
				y1 = right;
			}
		}
	}
	
	printf("Max Sub-Matrix Sum = %d with (%d, %d) -> (%d, %d)\n", max_sum, x0, y0, x1, y1);
}
int kadane_1d(int A[], int n, int *l, int *r)
{
	int sum = 0, ans = 0;
	int init = 0;
	for(int i = 0;i < n;i++)
	{
		sum += A[i];
		if(sum > ans)
		{
			ans = sum;
			*l = init;
			*r = i;
		}
		if(sum < 0)
		{
			sum = 0;
			init = i+1;
		}
	}
	
	if(ans > 0)	//only non-positive numbers on array A
		return ans;
	else		//take the higher element
	{
		ans = A[0];
		*l = *r = 0;
		for(int i = 1;i < n;i++)
			if(A[i] > ans)
			{
				ans = A[i];
				*l = *r = i;
			}
		return ans;
	}
}
