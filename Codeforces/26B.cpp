#include<bits/stdc++.h>
using namespace std;
int main()
{
    char arr[1000010];
    scanf("%s",arr);
    int i,j,k,x,y,ans,curr,len,temp;
    len = strlen(arr);
    curr = 0;
    ans = 0;
    for(i=0;i<len;i++)
    {
        if(arr[i] == '(')
            curr = max(1,curr+1);
        else
            curr--;
        if(arr[i] == ')' && curr >= 0)
            ans++;
    }
    printf("%d\n",ans*2);
    return 0;
}
