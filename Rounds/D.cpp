#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int r1, x1, y1, r2, x2, y2;
		scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2);
		double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		if(d <= (r1-r2))
			cout<<"Rich\n";
		else
			cout<<"Dead\n";
	}
	return 0;
}
