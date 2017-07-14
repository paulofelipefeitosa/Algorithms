#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int tran[10][10];
	map<string, int>map;
	string str;
	map["+x"] = 1; map["-x"] = 2; map["+y"] = 3; map["-y"] = 4; map["+z"] = 5; map["-z"] = 6;
	tran[map["+x"]][map["+y"]] = tran[map["-x"]][map["-y"]] = tran[map["+y"]][map["+z"]] = tran[map["+y"]][map["-z"]] = map["+y"];
	tran[map["+x"]][map["-y"]] = tran[map["-x"]][map["+y"]] = tran[map["-y"]][map["+z"]] = tran[map["-y"]][map["-z"]] = map["-y"];
	tran[map["+x"]][map["+z"]] = tran[map["-x"]][map["-z"]] = tran[map["+z"]][map["+y"]] = tran[map["+z"]][map["-y"]] = map["+z"];
	tran[map["+x"]][map["-z"]] = tran[map["-x"]][map["+z"]] = tran[map["-z"]][map["+y"]] = tran[map["-z"]][map["-y"]] = map["-z"];
	tran[map["+y"]][map["-y"]] = tran[map["-y"]][map["+y"]] = tran[map["+z"]][map["-z"]] = tran[map["-z"]][map["+z"]] = map["+x"];
	tran[map["+y"]][map["+y"]] = tran[map["-y"]][map["-y"]] = tran[map["+z"]][map["+z"]] = tran[map["-z"]][map["-z"]] = map["-x"];
	int l, act, bef, op;
	while(cin>>l, l > 0)
	{
		bef = 1;
		for(int i=1;i<l;i++)
		{
			cin>>str;
			if(str == "No")
				continue;
			op = map[str];
			bef = tran[bef][op];
		}
		if(bef==1)
			cout<<"+x"<<endl;
		else if(bef==2)
			cout<<"-x"<<endl;
		else if(bef==3)
			cout<<"+y"<<endl;
		else if(bef==4)
			cout<<"-y"<<endl;
		else if(bef==5)
			cout<<"+z"<<endl;
		else
			cout<<"-z"<<endl;
	}
	return 0;
}
