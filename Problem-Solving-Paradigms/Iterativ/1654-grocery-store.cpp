#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c, d, e, l;
	for(int i = 1;i <= 2000 && i*i*i*i <= 2000000000;i++)
		for(int j = i;j <= 2000-i && i*j*j*j <= 2000000000;j++)
			for(int k = j;k <= 2000-i-j && i*j*k*k <= 2000000000;k++)
			{
				b = i*j*k;
				c = 1000000;
				if(b == c)
					continue;
				
				a = i+j+k;
				d = a*c;
				e = b-c;
				
				if(d % e != 0)
					continue;
				// l = ((i+j+k)*1000000)/((i*j*k)-1000000)
				l = d/e;
				if(k > l)
					continue;
				if(a+l > 2000)
					continue;
				if(b*l > 2000000000)
					continue;
				
				printf("%.2f %.2f %.2f %.2f\n", i/100.00, j/100.00, k/100.00, l/100.00);
			}
				/*for(int l = k+1;l <= 2000 && (ijkl = ijk*l) <= 2000000000 && (i+j+k+l) <= 2000;l++)
				{
					//printf("%.2f %.2f %.2f %.2f\n", i/100.00, j/100.00, k/100.00, l/100.00);
					if(ijkl == ((i+j+k+l)*1000000))
						printf("%.2f %.2f %.2f %.2f\n", i/100.00, j/100.00, k/100.00, l/100.00);
				}*/
	return 0;
}
