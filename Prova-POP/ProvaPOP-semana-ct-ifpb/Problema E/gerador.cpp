#include <bits/stdc++.h>
using namespace std;

int main(){

	int val[3], qtd[3];
	
	string colors[] = {"azul", "amarela", "vermelha"};
	
	srand(time(NULL));
	
	int n = (rand() % 1000 + 1);
	val[0] = (rand() % 100 + 1);
	val[1] = (rand() % 100 + 1);
	val[2] = (rand() % 100 + 1);
	
	qtd[0] = (rand() % 100 + 1);
	qtd[1] = (rand() % 100 + 1);
	qtd[2] = (rand() % 100 + 1);
	
	cout << n << endl;
	cout << qtd[0] << ' ' << qtd[1] << ' ' << qtd[2] << endl;
	cout << val[0] << ' ' << val[1] << ' ' << val[2] << endl;
	

	for(int j = 0 ; j < n ; j++)
		cout << colors[rand() % 3] << endl;
	return 0;
}
