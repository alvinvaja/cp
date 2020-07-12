/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int arr[200200];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> tc;
    int inc = 1;
    while(tc--)
    {
        cin >> n;
        int maxi = -1;
        for(i=1;i<=n;i++) cin >> arr[i];
        ans = 0;
        for(i=1;i<=n;i++) {
            if(i < n) {
                if(arr[i] > maxi && arr[i] > arr[i+1]) {
                    ans++;
                }
            }
            else if(arr[i] > maxi) {
                ans++;
            }
            maxi = max(maxi, arr[i]);
        }
        printf("Case #%d: %d\n", inc++, ans);
    }
    return 0;
}
