/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int arr[200200];
int dp[10010][4];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> tc;
    int inc = 1;
    while(tc--)
    {
        cin >> n;
        for(i=1;i<=n;i++) cin >> arr[i];
        for(i=2;i<=n;i++) {
            for(j=0;j<4;j++) dp[i][j] = 1e9;
        }
        for(i=2;i<=n;i++) {
            for(j=0;j<4;j++) {
                for(k=0;k<4;k++) {
                    if(arr[i] > arr[i-1] && j > k) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                    } else if(arr[i] < arr[i-1] && j < k) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                    } else if(arr[i] == arr[i-1] && j == k) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + 1);
                    }
                }
            }
        }
        int chaeng = 1e9;
        for(i=0;i<4;i++) chaeng = min(chaeng, dp[n][i]);
        printf("Case #%d: %d\n", inc++, chaeng);
    }
    return 0;
}
