#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, idx, i, j, k, ans,curr;
    char arr[20];
    scanf("%s",arr);
    int len = strlen(arr);
    int diff = 753;
    ans = 1e9;
    for(i=0;i<len-2;i++)
    {
        curr = 0;
        curr += (arr[i]-'0')*100;
        curr += (arr[i+1]-'0')*10;
        curr += (arr[i+2]-'0');
        ans = min(ans,abs(curr-diff));
    }
    printf("%d\n",ans);
    return 0;
}
