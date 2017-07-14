#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int vetor[3];
	
	cin>>vetor[0]>>vetor[1]>>vetor[2];
	
	sort(vetor, vetor+3); // preciso ordernar o vetor para que o next_permutation gere todas as permutações desde o inicio
	
	bool flag = false;
	do
	{
		if(vetor[0] - vetor[1] == 0)// Teste (A - B)
		{
			flag = true;
			break;
		}
		else if(vetor[1] - vetor[0] == 0)// Teste (B - A)
		{
			flag = true;
			break;
		}
		else if(abs(vetor[0] - vetor[1]) == vetor[2])// Teste de Ri, ou seja, inserindo um terceiro número
		{
			flag = true;
			break;
		}
	}while(next_permutation(vetor, vetor+3));
	
	if(flag == true)
		printf("S\n");
	else
		printf("N\n");
	
	return 0;
}
