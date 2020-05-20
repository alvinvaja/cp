/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[200200];
ll pref[200200];
ll suff[200200];
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int tc = 1;
    while(tc--) {
        scanf("%d",&n);
        int gcd = 0;
        for(i=1;i<=n;i++) {
            scanf("%lld",&arr[i]);
            pref[i] = __gcd(pref[i-1], arr[i]);
        }
        for(i=n;i>0;i--) {
            suff[i] = __gcd(suff[i+1], arr[i]);
        }
        vector<ll> vi;
        for(i=1;i<=n;i++) {
            ll a = arr[i];
            ll b = __gcd(pref[i-1], suff[i+1]);
            ll gcd = __gcd(a,b);
            vi.push_back(a*b/gcd);
        }
        ll chaeng = 0;
        for(auto x : vi) {
            chaeng = __gcd(chaeng, x);
        }
        cout << chaeng << endl;
    }
	return 0;
}