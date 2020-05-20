/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> mp;
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc = 1;
    while(tc--)
    {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll chaeng = 0;
        for(i=a;i<=b;i++) {
            mp[i+b]++;
            mp[i+c+1]--;
        }
        ll sana = 0;
        for(ll it = a + b; it <= b + c; it++) {
            sana += mp[it];
            chaeng += max(0LL, 1LL*sana*(min(d + 1, it) - c));
        }
        cout << chaeng << endl;
    }
    return 0;
}