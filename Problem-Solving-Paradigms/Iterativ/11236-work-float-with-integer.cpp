#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int l, a, b, c = 1000000, d, e;
	for(long long int i = 1;i<2000 && (i*i*i*i)<=2000000000;i++)
		for(long long int j = i;j<2000-i && (i*j*j*j)<=2000000000;j++)
			for(long long int k = j;k<2000-i-j && (i*j*k*k)<=2000000000;k++)
			{//formula (p1+p2+p3+p4)*10^6 = (p1*p2*p3*p4) => sendo a = p1+p2+p3, b = p1*p2*p3 e c = 10^6 => c(a + p4) = b*p4 => p4 = c*a/b-c
				b = i * j * k;
				if(b!=c)
				{
					a = i + j + k;
					d = c*a; e = b-c;
					if(d%e==0)
					{
						l = d/e;
						if(l >= k && a+l <= 2000 && b*l < 2000000001)
							printf("%.2f %.2f %.2f %.2f\n", i/100.00, j/100.00, k/100.00, l/100.00);
					}
				}
			}
	return 0;
}
