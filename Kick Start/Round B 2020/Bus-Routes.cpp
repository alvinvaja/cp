/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[1010];
int main()
{
    int n,i,j,k,x,y,ans,temp,curr,m;
    int tc;
    int inc = 1;
    cin >> tc;
    while(tc--)
    {
        ll day;
        cin >> n >> day;
        for(i=1;i<=n;i++) {
            cin >> arr[i];
        }
        ll chaeng = day;
        for(i=n;i>0;i--) {
            chaeng -= chaeng % arr[i];
        }
        printf("Case #%d: %lld\n", inc++, chaeng);
    }
    return 0;
}
