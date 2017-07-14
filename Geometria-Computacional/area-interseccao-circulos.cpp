#include <bits/stdc++.h>
#define EPS 1e-12
#define PI 2*acos(0.0)
using namespace std;
struct point
{
	long double x, y;
};
point ans[2];
bool FindInterPoints(point C1, long double r1, point C2, long double r2);
int main()
{
	point C1, C2;
	long double r1, r2;
	
	cin>>C1.x>>C1.y>>r1;
	cin>>C2.x>>C2.y>>r2;
	
	if(C1.x == C2.x && C1.y == C2.y && r1 == r2)
	{
		printf("%.12Lf\n", PI*r1*r1);
		return 0;
	}
	if(C1.x == C2.x && C1.y == C2.y && r1 != r2)
	{
		long double A1 = PI*r1*r1;
		long double A2 = PI*r2*r2;
		printf("%.12Lf\n", min(A1, A2));
		return 0;
	}
	
	if(FindInterPoints(C1, r1, C2, r2))
	{
		printf("(%.12Lf, %.12Lf) and (%.12Lf, %.12Lf)\n\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
		
		long double D = sqrt(((ans[0].x - ans[1].x)*(ans[0].x - ans[1].x)) + ((ans[0].y - ans[1].y)*(ans[0].y - ans[1].y)));
		
		printf("%.12Lf and %.12Lf\n\n", D*D, 2*r1*r1);
		
		double t1 = 1.00 - (double)((D*D)/(2*r1*r1));
		double t2 = 1.00 - (double)((D*D)/(2*r2*r2));
		
		double teta = acos(t1);
		double alpha = acos(t2);
		
		printf("%.12lf and %.12lf\n\n", teta, alpha);
		
		double A1 = ((r1*r1)/2.00)*(teta - sin(teta));
		double A2 = ((r2*r2)/2.00)*(alpha - sin(alpha));
		
		printf("%.12lf and %.12lf\n\n", sin(teta), sin(alpha));
		
		printf("%.10lf + %.10lf = %.10lf\n\n", A1, A2, A1+A2);
		//printf("%.12lf\n", A1+A2);
	}
	else
	{
		long double D = sqrt((C1.x - C2.x)*(C1.x - C2.x) + (C1.y - C2.y)*(C1.y - C2.y));
		if(r1 + r2 > D)
		{
			long double A1 = PI*r1*r1;
			long double A2 = PI*r2*r2;
			printf("%.12Lf\n", min(A1, A2));
		}
		else
			printf("%.12Lf\n", 0.00);
	}
		
	return 0;
}
bool FindInterPoints(point C1, long double r1, point C2, long double r2)
{
	long double a, b;
	long double c, d, e;
	long double t1, t2, delta;
	
	if(C1.x != C2.x)
	{
		a = ((r2*r2) - (r1*r1) + (C1.x*C1.x) - (C2.x*C2.x) + (C1.y*C1.y) - (C2.y*C2.y))/(2.00*(C1.x-C2.x));
		if(C2.y == C1.y)
			b = 0.0;
		else
			b = (C2.y-C1.y)/(C1.x-C2.x);
		
		c = (b*b) + 1.00;
		d = (2.00*a*b) - (2.00*b*C1.x) - (2.00*C1.y);
		e = (C1.x*C1.x) + (C1.y*C1.y) + (a*a) - (r1*r1) - (2.00*a*C1.x);
		
		t1 = (d*d);
		t2 = (4*c*e);
		if(t2 >= t1)
			return false;
	}
	else
	{
		a = ((r2*r2) - (r1*r1) + (C1.x*C1.x) - (C2.x*C2.x) + (C1.y*C1.y) - (C2.y*C2.y))/(2.00*(C1.y-C2.y));
		if(C2.x == C1.x)
			b = 0.0;
		else
			b = (C2.x-C1.x)/(C1.y-C2.y);
		
		c = (b*b) + 1.00;
		d = (2.00*a*b) - (2.00*b*C1.y) - (2.00*C1.x);
		e = (C1.x*C1.x) + (C1.y*C1.y) + (a*a) - (r1*r1) - (2.00*a*C1.y);
		
		t1 = (d*d);
		t2 = (4*c*e);
		if(t2 >= t1)
			return false;
	}
	delta = t1 - t2;
	
	ans[0].y = (sqrt(delta) - d)/(2.00*c);
	ans[1].y = (-sqrt(delta) - d)/(2.00*c);
	ans[0].x = a + (b*ans[0].y);
	ans[1].x = a + (b*ans[1].y);
	
	return true;
}
