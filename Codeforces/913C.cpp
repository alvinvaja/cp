#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,k,x,y,ans,curr,temp;
    scanf("%lld %lld",&n,&k);
    long long int arr[n+5];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    for(i=1;i<n;i++)
    {
        arr[i] = min(arr[i], 2 * arr[i-1]);
    }
    ans = 1e18;
    curr = 0;
    for(i=n-1;i>=0;i--)
    {
        temp = k / (1 << i);
        curr += temp*arr[i];
        k -= (temp * (1 << i));
        if(k > 0)
        {
            ans = min(ans, curr + arr[i]);
        }
        else
        {
            ans = min(ans, curr);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
