#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
int main()
{
	int t, vet[MAX];
	string str;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", &vet[i]);
		sort(vet, vet+n);
		int a = vet[0], b = vet[1], ans = 0;
		int A, B;
		for(int i = n-1;i > 1;i-=2)
		{
			if((i-1) > 1)//ainda tem dois
			{
				A = vet[i];
				B = vet[i-1];
				if(((a<<1) + A + B) < ((b<<1) + a + A))//melhor passar o menor nos dois
				{
					str += to_string(a) + " " + to_string(B) + "\n"
							+ to_string(a) + "\n"
							+ to_string(a) + " " + to_string(A) + "\n"
							+ to_string(a) + "\n";
					ans += (a<<1) + A + B;
				}
				else//melhor passar o dois menores
				{
					str += to_string(a) + " " + to_string(b) + "\n"
							+ to_string(a) + "\n"
							+ to_string(B) + " " + to_string(A) + "\n"
							+ to_string(b) + "\n";
					ans += (b<<1) + a + A;
				}
			}
			else//sobra um
			{
				A = vet[i];
				str += to_string(a) + " " + to_string(A) + "\n"
						+ to_string(a) + "\n";
				ans += a + A;
			}
		}
		if(n == 1)
		{
			str += to_string(a) + "\n";
			ans += a;
		}
		else
		{
			str += to_string(a) + " " + to_string(b) + "\n";
			ans += b;
		}
		cout<<ans<<"\n"<<str;
		if(t)
			putchar('\n');
		str.clear();
	}
	return 0;
}

