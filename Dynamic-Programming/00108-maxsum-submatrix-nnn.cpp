#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int matrix[MAX][MAX];

void kadane_2d(int row, int col);
int kadane_1d(int A[], int n);

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf("%d", &matrix[i][j]);
	
	kadane_2d(n, n);
	
	return 0;
}
void kadane_2d(int row, int col)
{
	int sum_row[row], sum_cur;
	int max_sum = -(1<<30);
	
	for(int left = 0;left < col;left++)
	{
		memset(sum_row, 0, sizeof(sum_row));
		for(int right = left;right < col;right++)
		{
			for(int i = 0;i < row;i++)
				sum_row[i] += matrix[i][right];
				
			sum_cur = kadane_1d(sum_row, row);
			
			max_sum = max(max_sum, sum_cur);
		}
	}
	printf("%d\n", max_sum);
}
int kadane_1d(int A[], int n)
{
	int sum = 0, ans = 0;
	for(int i = 0;i < n;i++)
	{
		sum += A[i];
		if(sum > ans)
			ans = sum;
		if(sum < 0)
			sum = 0;
	}
	
	if(ans > 0)	//only non-positive numbers on array A
		return ans;
	else		//take the higher element
	{
		ans = A[0];
		for(int i = 1;i < n;i++)
			ans = max(ans, A[i]);
		return ans;
	}
}
