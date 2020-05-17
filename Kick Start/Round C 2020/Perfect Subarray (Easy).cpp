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
    int batas = 1e7;
    vector<ll> vi;
    for(i=0;;i++) {
        ll res = 1LL*i*i;
        if(res > batas) break;
        vi.push_back(res);
    }
    while(tc--)
    {
        cin >> n;
        ll chaeng = 0;
        map<int, int> mp;
        mp[0] = 1;
        int now = 0;
        batas = 100*n;
        for(i=1;i<=n;i++) {
            cin >> curr;
            now += curr;
            for(auto x : vi) {
                if(x > batas) break;
                int need = now - x;
                chaeng += mp[need];
            }
            mp[now]++;
        }
        printf("Case #%d: %lld\n", inc++, chaeng);
    }
	return 0;
}
