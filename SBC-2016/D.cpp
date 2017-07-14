#include <bits/stdc++.h>
using namespace std;
int main()
{
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	
	if(C % A != 0 || A % B == 0 || D % C == 0 || A == B || C == D) // Verificar os dois casos porque as instâncias do problemas não dizem muita coisa sobre esses valores
	{
		printf("-1\n");
		return 0;
	}
	
	int n, y, w = C/A;
	bool flag = false;
	
	for(int x = 1;x <= w && !flag;x++)
	{
		if(w % x == 0)
		{
			y = w/x;//x pode não ser divisor de div
			n = A*x;
			if(n % B != 0 && D % n != 0)
			{
				printf("%d\n", n);
				flag = true;
			}
		}
	}
	
	if(!flag)
		printf("-1\n");
	return 0;
}
