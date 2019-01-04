#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,valid;
int arr[20];
void dfs(int deg, int curr)
{
    if(curr == n && deg % 360 == 0)
    {
        valid = 1;
        return;
    }
    if(curr == n)
    {
        return;
    }
    dfs(deg+arr[curr],curr+1);
    dfs(deg-arr[curr],curr+1);
}
int main()
{
    scanf("%d",&n);
    valid = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    dfs(0,0);
    if(valid == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
