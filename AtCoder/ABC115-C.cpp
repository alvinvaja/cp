#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, idx, i, j, k, ans,curr;
    scanf("%d %d",&n,&k);
    ans = 1e9+5;
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    k--;
    sort(arr,arr+n);
    for(i=0;i<n-k;i++)
    {
        ans = min(ans,arr[i+k] - arr[i]);
    }
    printf("%d\n",ans);
    return 0;
}
