/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[100100];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    int a, r;
    cin >> n >> a >> r >> m;
    ll sum = 0;
    for(i=1;i<=n;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr+1, arr+n+1);
    ll chaeng = 1e18;
    ll realSum = sum;
    ll now = 0;
    for(i=1;i<=n;i++) {
        // just add and removes
        ll up = 1LL*(1LL*arr[i]*(i-1) - now);
        sum -= arr[i];
        now += arr[i];
        ll down = 1LL*(sum - (1LL*arr[i]*(n - i)));
        ll naikturun = 1LL*up*a + 1LL*down*r;
        chaeng = min(chaeng, naikturun);

        // with moves operations
        ll pindah = min(up, down);
        up -= pindah;
        down -= pindah;
        naikturun = 1LL*up*a + 1LL*down*r + 1LL*pindah*m;
        chaeng = min(chaeng, naikturun);
    }

    // middle breakpoints for maximum moves operations
    double avg = realSum / (double) n;
    vector<ll> vi;
    // consider two breakpoints since average can be non-integers
    vi.push_back(floor(avg));
    vi.push_back(ceil(avg));
    for(auto x : vi) {
        ll up = 0, down = 0;
        ll cntUp = 0, cntDown = 0;
        for(i=1;i<=n;i++) {
            if(arr[i] < x) {
                up += arr[i];
                cntUp++;
            } else if(arr[i] > x) {
                down += arr[i];
                cntDown++;
            }
        }
        up = x*cntUp - up;
        down = down - x*cntDown;
        ll pindah = min(up, down);
        up -= pindah;
        down -= pindah;
        ll tot = 1LL*up*a + 1LL*down*r + 1LL*pindah*m;
        chaeng = min(chaeng, tot);
    }
    cout << chaeng << endl;
    return 0;
}
