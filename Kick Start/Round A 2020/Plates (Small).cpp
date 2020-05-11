/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[55][33];
stack<int> st[55];
int dp[55][33];
int main()
{
    int n,i,j,k,x,y,ans,temp,curr,m;
    int tc;
    cin >> tc;
    int inc = 1;
    int p;
    while(tc--)
    {
        cin >> n >> k >> p;
        memset(dp, 0, sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            {
                scanf("%d",&arr[i][j]);
                dp[i][j] = dp[i][j-1] + arr[i][j];
            }
        }
        int chaeng = 0;
        if(n == 1) chaeng = dp[1][p];
        else if(n == 2)
        {
            for(i=0;i<=k;i++)
            {
                for(j=0;j<=k;j++)
                {
                    if(i+j != p) continue;
                    chaeng = max(chaeng, dp[1][i] + dp[2][j]);
                }
            }
        }
        else if(n == 3)
        {
            for(i=0;i<=k;i++)
            {
                for(j=0;j<=k;j++)
                {
                    for(int a = 0;a <= k; a++)
                    {
                        if(i+j+a != p) continue;
                        chaeng = max(chaeng, dp[1][i] + dp[2][j] + dp[3][a]);
                    }
                }
            }
        }
        printf("Case #%d: %d\n", inc++, chaeng);
    }
    return 0;
}
