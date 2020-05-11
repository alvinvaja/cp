/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100100];
int main()
{
    int n,i,j,k,x,y,ans,temp,curr,m;
    int tc;
    cin >> tc;
    int inc = 1;
    while(tc--)
    {
        ll cost;
        cin >> n >> cost;
        for(i=1;i<=n;i++) cin >> arr[i];
        sort(arr+1,arr+n+1);
        int chaeng = 0;
        for(i=1;i<=n;i++)
        {
            if(cost >= arr[i])
            {
                chaeng++;
                cost -= arr[i];
            }
            else break;
        }
        printf("Case #%d: %d\n", inc++, chaeng);
    }
    return 0;
}
