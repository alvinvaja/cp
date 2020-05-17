/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,i,j,k,x,y,ans,curr,m;
    int tc;
    int inc = 1;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        int chaeng = 0;
        int now = k;
        for(i=1;i<=n;i++) {
            cin >> curr;
            if(curr == now) {
                now--;
            } else {
                now = k;
                if(curr == now) now--;
            }
            if(now == 0) {
                chaeng++;
                now = k;
            }
        }
        printf("Case #%d: %d\n", inc++, chaeng);
    }
	return 0;
}
