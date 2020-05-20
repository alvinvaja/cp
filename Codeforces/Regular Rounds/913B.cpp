#include<bits/stdc++.h>
using namespace std;
vector<int> vi[1010];
int main()
{
    int n,i,j,k,x,y,ans,curr;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        scanf("%d",&curr);
        vi[curr].push_back(i);
    }
    int valid = 1;
    for(i=1;i<=n;i++)
    {
        if(vi[i].size() == 0)
            continue;
        int cnt = 0;
        for(j=0;j<vi[i].size();j++)
        {
            int temp = vi[i][j];
            if(vi[temp].size() == 0)
                cnt++;
        }
        if(cnt < 3)
            valid = 0;
    }
    if(valid == 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
