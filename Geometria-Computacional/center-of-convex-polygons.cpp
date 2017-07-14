#include <bits/stdc++.h>
#define MAX 105
#define EPS 1e-6

using namespace std;

double mat[MAX][3];
double ans[3];
int lin, col = 2;

bool GaussianElimination();

int main()
{
	double x[MAX], y[MAX];
	
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%lf %lf", &x[i], &y[i]);

	lin = n-1;
	for(int i = 0;i < lin;i++)
	{
		mat[i][0] = (2.00*x[i+1]) - (2.00*x[0]);
		mat[i][1] = (2.00*y[i+1]) - (2.00*y[0]);
		mat[i][2] = (x[i+1]*x[i+1]) - (x[0]*x[0]) + (y[i+1]*y[i+1]) - (y[0]*y[0]);
	}
	
	for(int i = 0;i < lin;i++)
		printf("%lf %lf %lf\n", mat[i][0], mat[i][1], mat[i][2]);
	putchar('\n');
	
	bool sol = GaussianElimination();
	
	if(sol)
	{
		for(int i = 0;i < col;i++)
			printf("%.2lf ", ans[i]);
		putchar('\n');
	}
	
	return 0;
}
bool GaussianElimination()
{
	int i, j, k, l;
	double t, f;
	
	for(j = 0;j < col;j++)
	{
		l = j;
		for(i = j + 1;i < lin;i++)
			if(fabs(mat[i][j]) > fabs(mat[l][j]))
				l = i;
		
		for(k = j;k <= col;k++)
		{
			t = mat[j][k];
			mat[j][k] = mat[l][k];
			mat[l][k] = t;
		}
		
		for(i = j+1;i < lin;i++)
		{
			f = mat[i][j] / mat[j][j];
			for(k = col;k >= j;k--)
				mat[i][k] -= mat[j][k] * f;
		}
		for(int m = 0;m < lin;m++)
			printf("%lf %lf %lf\n", mat[m][0], mat[m][1], mat[m][2]);
		putchar('\n');
	}
	
	for(j = col;j < lin;j++)
		if(fabs(mat[j][col]) > EPS)
			return false;
	
	for(j = col-1;j >= 0;j--)
	{
		for(t = 0.0, k = j + 1;k < col;k++)
			t += mat[j][k] * ans[k];
		ans[j] = (mat[j][col] - t) / mat[j][j];
	}
	
	return true;
}
