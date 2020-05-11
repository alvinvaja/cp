#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, idx, i, j, k, ans,curr;
    scanf("%d",&n);
    int arr[n];
    int maxi = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(maxi < arr[i])
        {
            maxi = arr[i];
            idx = i;
        }
    }
    ans = 0;
    for(i=0;i<n;i++)
    {
        if(idx == i)
        {
            ans += (arr[i]/2);
        }
        else
        {
            ans += arr[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
