/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[100100];
int dp[100100];
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int tc;
    cin >> tc;
    while(tc--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++) {
            scanf("%d",&arr[i]);
            dp[i] = 1;
            int akar = sqrt(i);
            for(j=1;j<=akar;j++) {
                if(i % j == 0) {
                    if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
                    curr = i / j;
                    if(arr[i] > arr[curr]) {
                        dp[i] = max(dp[i], dp[curr] + 1);
                    }
                }
            }
        }
        int chaeng = 0;
        for(i=1;i<=n;i++) chaeng = max(chaeng, dp[i]);
        printf("%d\n", chaeng);
    }
	return 0;
}