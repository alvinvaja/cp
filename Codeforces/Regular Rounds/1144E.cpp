/*
    Mbak Rose Dong
*/
#include<bits/stdc++.h>
using namespace std;
int low[200200];
int high[200200];
int jwb[200200];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    string a,b;
    cin >> n >> a >> b;
    for(i=0;i<n;i++)
    {
        low[i] = a[i] - 'a';
    }
    for(i=0;i<n;i++)
    {
        high[i] = b[i] - 'a';
    }
    int carry = 0;
    for(i=0;i<n;i++)
    {
        curr = (low[i] + high[i]) / 2 + carry;
        jwb[i] = curr;
        j = i;
        while(jwb[j] >= 26)
        {
            jwb[j] -= 26;
            j--;
            jwb[j]++;
        }
        if(abs(low[i]-high[i]) % 2 == 1)
        {
            carry = 13;
        }
        else
        {
            carry = 0;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%c",'a'+jwb[i]);
    }
    printf("\n");
    return 0;
}
