#include <stdio.h>
#include <math.h>
#define EPS 1e-9
using namespace std;
int p, q, r, s, t, u;
double function(double x);
int main()
{
	int i, N = 50;
	double lb, ub, mid;
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
	{
		if(function(0) * function(1) > 0)//Teorema do valor intermediário
		{
			puts("No solution");
			continue;
		}
		lb = 0; ub = 1; mid = 0.5;
		i = 1;
		while(fabs(function(mid)) > EPS && i < N)
		{
			mid = (lb + ub)/2.0;
			if(function(lb) * function(mid) > 0)
				lb = mid;
			else
				ub = mid;
			i++;
		}
		printf("%.4lf\n", mid);
	}
	return 0;
}
double function(double x)
{
	return p/exp(x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
