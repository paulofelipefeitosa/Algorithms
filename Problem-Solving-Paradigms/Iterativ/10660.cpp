#include <bits/stdc++.h>
#define MAX 26
using namespace std;
int price[MAX], pre[MAX][MAX], x, y, n, a, b, c, d, e, sum, cur;
pair<int,int>coord[MAX];
set<int>myset;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d", &x, &y);
            coord[i] = pair<int,int>(x, y);
            scanf("%d", &price[i]);
            myset.insert((x*5)+y);
        }
        if(n < 5)
        {
            for(int i=0;i<25 && (int)myset.size()<5;i++)
                if(myset.find(i)==myset.end())
                    myset.insert(i);
            auto it = myset.begin();
            printf("%d", *it);
            it++;
            for(;it!=myset.end();it++)
                printf(" %d", *it);
            putchar('\n');
        }
        else
        {
            sort(coord, coord+n);
            for(int i=0;i<n;i++)
            {
                pre[i][i] = 1<<30;
                for(int j=i+1;j<n;j++)
                    pre[i][j] = pre[j][i] = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
            }
            sum = 1<<30;
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                    for(int k=j+1;k<n;k++)
                        for(int l=k+1;l<n;l++)
                            for(int m=l+1;m<n;m++)
                            {
                                cur = 0;
                                for(int o=0;o<n;o++)
                                    cur += (pre[o][i]+pre[o][j]+pre[o][k]+pre[o][l]+pre[o][m])*price[o];
                                if(sum < cur)
                                    sum = cur, a = i, b = j, c = k, d = l, e = m;
                            }
            printf("%d %d %d %d %d\n", (coord[a].first*5)+coord[a].second, (coord[b].first*5)+coord[b].second, (coord[c].first*5)+coord[c].second, (coord[d].first*5)+coord[d].second, (coord[e].first*5)+coord[e].second);
        }
        myset.clear();
    }
    return 0;
}
