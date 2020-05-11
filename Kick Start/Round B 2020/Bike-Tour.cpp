/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int h[105];
int main()
{
    int n,i,j,k,x,y,ans,temp,curr,m;
    int tc;
    int inc = 1;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for(i=1;i<=n;i++) {
            cin >> h[i];
        }
        int chaeng = 0;
        for(i=2;i<n;i++) {
            if(h[i] > max(h[i-1], h[i+1])) {
                chaeng++;
            }
        }
        printf("Case #%d: %d\n", inc++, chaeng);
    }
    return 0;
}
