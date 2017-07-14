#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int> >m1(2, vector<int>(4)), m2(2, vector<int>(4));
bool isequal(vector<vector<int> >&M1, vector<vector<int> >&M2);
int main()
{
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 4;j++)
            scanf("%d", &m1[i][j]);
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 4;j++)
            scanf("%d", &m2[i][j]);
    
    return 0;
}
int solve(vector<vector<int> >m)
{
    if(isequal(m, m2))
        return 0;
    for()
}
bool isequal(vector<vector<int> >&M1, vector<vector<int> >&M2)
{
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 4;j++)
            if(M1[i][j] != M2[i][j])
                return false;
    return true;
}
