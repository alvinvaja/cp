/*
    Mbak Rose Dong
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> arr[100100];
bool ada[100100];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> tc;
    while(tc--)
    {
        int q;
        scanf("%d %d %d",&n,&m,&q);
        for(i=1;i<=m;i++)
        {
            arr[i] = make_pair(-1,-1);
            ada[i] = 0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&y);
            for(j=x;j<=y;j++)
            {
                ada[j] = 1;
            }
        }
        i = 1;
        while(i <= m)
        {
            curr = 0;
            for(j=i;j<=m;j++)
            {
                if(ada[j] == 0)
                {
                    curr++;
                }
                else
                {
                    break;
                }
            }
            if(curr > 0)
            {
                while(curr > 0)
                {
                    arr[curr] = make_pair(i,j-1);
                    i++;
                    curr--;
                }
            }
            i = j+1;
        }
        while(q--)
        {
            scanf("%d",&curr);
            printf("%d %d\n",arr[curr].first, arr[curr].second);
        }
    }
    return 0;
}
