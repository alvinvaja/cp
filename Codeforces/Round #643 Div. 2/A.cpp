#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> tc;
    while(tc--)
    {
        ll a, b;
        cin >> a >> b;
        b--;
        while(b--) {
            ll now = a;
            ll mini = 10;
            ll maxi = 0;
            while(now > 0) {
                maxi = max(maxi, now%10);
                mini = min(mini, now%10);
                now /= 10;
            }
            if(mini == 0) break;
            a += maxi*mini;
        }
        cout << a << endl;
    }
    return 0;
}