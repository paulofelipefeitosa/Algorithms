#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	ifstream out, solve;
	
	out.open("out", ifstream::in);
	solve.open("solve", ifstream::in);
	
	if(!out.is_open())
	{
		puts("Erro ao abrir o out");
		return 1;
	}
	if(!solve.is_open())
	{
		puts("Erro ao abrir o solve");
		return 1;
	}
	
	string buffer;
	stringstream ss;
	int line = 1, caso = 1;
	
	while(getline(out, buffer))
	{
		if(buffer.size()==0)
			caso++;
		int cont1 = 0, cont2 = 0;
		ss << buffer;
		while(ss >> buffer)
			cont1++;
		ss.clear();
		
		getline(solve, buffer);
		ss << buffer;
		while(ss >> buffer)
			cont2++;
		ss.clear();
		
		if(cont1!=cont2)
			cout<<"opa "<<line<<" in "<<caso<<endl;
		line++;
	}
	
	out.close();
	solve.close();
	
	return 0;
}

