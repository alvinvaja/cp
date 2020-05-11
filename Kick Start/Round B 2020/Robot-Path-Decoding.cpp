/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 1e9;
string s;
ll cnt[4];
ll kali[10];
pair<int,int> p[2020];
ll power(ll a, ll b)
{
    ll ret = 1;
    if(b == 0) return 1;
    while(b>0)
    {
        if(b%2==1)
        {
            ret = (ret * a) % mod;
        }
        b /= 2;
        a = (a * a) % mod;
    }
    return ret;
}
int main()
{
    int n,i,j,k,x,y,ans,temp,curr,m;
    int tc;
    int inc = 1;
    cin >> tc;
    while(tc--)
    {
        cin >> s;
        n = s.length();
        s = " " + s;
        ll nowx = 1;
        ll nowy = 1;
        for(i=1;i<=n;i++) {
            p[i] = {0, 0};
        }
        stack<pair<int,int> > st;
        for(i=1;i<=n;i++) {
            char c = s[i];
            if(c == '(') st.push({i, s[i-1] - '0'});
            else if(c == ')') {
                p[i] = {st.top().first, st.top().second};
                st.pop();
            }
        }
        for(i=1;i<10;i++) kali[i] = 0;
        for(i=0;i<4;i++) cnt[i] = 0;
        for(i=1;i<=n;i++) {
            char c = s[i];
            if(c == '(') {
                curr = s[i-1] - '0';
                kali[curr]++;
            } else if(c == ')') {
                kali[p[i].second]--;
            }
            ll chaeng = 1;
            for(j=1;j<10;j++) {
                chaeng *= power((ll)j, kali[j]);
                chaeng %= mod;
            }
            if(c == 'N') cnt[0] += chaeng;
            if(c == 'S') cnt[1] += chaeng;
            if(c == 'E') cnt[2] += chaeng;
            if(c == 'W') cnt[3] += chaeng;
            for(j=0;j<4;j++) cnt[j] %= mod;
        }
        nowx += cnt[1];
        nowx -= cnt[0];
        if(nowx < 1) {
            nowx += mod;
        }
        nowy += cnt[2];
        nowy -= cnt[3];
        if(nowy < 1) {
            nowy += mod;
        }
        printf("Case #%d: %lld %lld\n", inc++, nowy, nowx);
    }
    return 0;
}
