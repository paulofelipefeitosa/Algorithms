#include <bits/stdc++.h>
using namespace std;
int main()
{
	int vet[] = {10, 20, 30, 30, 30, 40, 50};
	printf("%d\n", lower_bound(vet, vet+7, 30) - vet);
	printf("%d\n", upper_bound(vet, vet+7, 35) - vet);
	return 0;
}
