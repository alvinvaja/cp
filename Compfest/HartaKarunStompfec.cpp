/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
    Mbak Seulgi Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod1 = 1e9+7;
const int mod2 = 1e9+9;
const int p1 = 31;
const int p2 = 53;
ll pp1[300300], pp2[300300];
string s[200100];
string kamus[200100];
int kiri[300300], kanan[300300], awal[200200], akhir[200200];
int seg[500500];
vector<pair<ll,ll> > segWord[200100];
map<pair<ll,ll>,bool> mp;

// segment tree tiap kata
void buildWord(int idx, int l, int r, int i)
{
    if(l == r) {
        segWord[i][idx].first = (1LL * (s[i][l-1]-'a'+1) * pp1[l-1]) % mod1;
        segWord[i][idx].second = (1LL * (s[i][l-1]-'a'+1) * pp2[l-1]) % mod2;
        return;
    }
    int mid = (l+r) / 2;
    buildWord(idx*2, l, mid, i);
    buildWord(idx*2+1, mid+1, r, i);
    segWord[i][idx].first = (segWord[i][idx*2].first + segWord[i][idx*2+1].first) % mod1;
    segWord[i][idx].second = (segWord[i][idx*2].second + segWord[i][idx*2+1].second) % mod2;
}

void updateWord(int idx, int l, int r, int index, char value, int i)
{
    if(l > index || r < index) return;
    if(l == r && l == index) {
        segWord[i][idx].first = (1LL * (value-'a'+1) * pp1[l-1]) % mod1;
        segWord[i][idx].second = (1LL * (value-'a'+1) * pp2[l-1]) % mod2;
        return;
    }
    int mid = (l+r) / 2;
    updateWord(idx*2, l, mid, index, value, i);
    updateWord(idx*2+1, mid+1, r, index, value, i);
    segWord[i][idx].first = (segWord[i][idx*2].first + segWord[i][idx*2+1].first) % mod1;
    segWord[i][idx].second = (segWord[i][idx*2].second + segWord[i][idx*2+1].second) % mod2;
}

pair<ll,ll> queryWord(int idx, int l, int r, int kiri, int kanan, int i)
{
    if(l > kanan || r < kiri) return {0, 0};
    if(l >= kiri && r <= kanan) return segWord[i][idx];
    int mid = (l+r) / 2;
    pair<ll,ll> li = queryWord(idx*2, l, mid, kiri, kanan, i);
    pair<ll,ll> re = queryWord(idx*2+1, mid+1, r, kiri, kanan, i);
    pair<ll,ll> res;
    res.first = (li.first+re.first)%mod1;
    res.second = (li.second+re.second)%mod2;
    return res;
}

// segment tree keseluruhan
void build(int idx, int l, int r)
{
    if(l == r) {
        if(mp[segWord[l][1]]) seg[idx]++;
        return;
    }
    int mid = (l+r) / 2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

void update(int idx, int l, int r, int index, int value)
{
    if(l > index || r < index) return;
    if(l == index && l == r) {
        seg[idx] = value;
        return;
    }
    int mid = (l+r) / 2;
    update(idx*2, l, mid, index, value);
    update(idx*2+1, mid+1, r, index, value);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

int query(int idx, int l, int r, int kiri, int kanan)
{
    if(l > kanan || r < kiri) return 0;
    if(l >= kiri && r <= kanan) return seg[idx];
    int mid = (l+r) / 2;
    int le = query(idx*2, l, mid, kiri, kanan);
    int ri = query(idx*2+1, mid+1, r, kiri, kanan);
    return le + ri;
}

void preprocess()
{
    pp1[0] = pp2[0] = 1;
    for(int i=1;i<=300000;i++) {
        pp1[i] = (1LL * pp1[i - 1] * p1) % mod1;
        pp2[i] = (1LL * pp2[i - 1] * p2) % mod2;
    }
}

ll power(ll a, ll b, ll mod)
{
    ll ret = 1;
    while(b>0) {
        if(b%2==1) ret = (ret*a) % mod;
        b /= 2;
        a = (a*a) % mod;
    }
    return ret;
}

int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> n;
    string full = "";
    for(i=1;i<=n;i++) {
        cin >> s[i];
        full += s[i];
        if(i < n) {
            full += ' ';
        }
    }
    preprocess();
    int q;
    cin >> m >> q;
    for(i=1;i<=m;i++) {
        cin >> kamus[i];
        string t = kamus[i];
        int sz = t.size();
        pair<ll,ll> seulgi;
        for(j=0;j<sz;j++) {
            seulgi.first += 1LL*(t[j]-'a'+1)*pp1[j];
            seulgi.first %= mod1;
            seulgi.second += 1LL*(t[j]-'a'+1)*pp2[j];
            seulgi.second %= mod2;
        }
        mp[seulgi] = 1;
    }
    int tot = full.size();
    int now = 1;
    for(i=0;i<tot;i++) {
        kiri[i+1] = now;
        if(full[i] == ' ') now++;
        if(i == 0 || full[i-1] == ' ') awal[now] = i + 1;
    }
    now = n;
    for(i=tot-1;i>=0;i--) {
        kanan[i+1] = now;
        if(full[i] == ' ') now--;
        if(i == tot-1 || full[i+1] == ' ') akhir[now] = i + 1;
    }

    for(i=1;i<=n;i++) {
        x = awal[i];
        y = akhir[i];
        segWord[i].resize(4 * (y - x + 5), {0, 0});
        buildWord(1, 1, y - x + 1, i);
    }

    build(1,1,n);
    full = " " + full;
    while(q--) {
        int tipe;
        scanf("%d", &tipe);
        if(tipe) {
            scanf("%d %d",&x,&y);
            int l, r;
            l = kiri[x] + 1;
            r = kanan[y] - 1;
            int chaeng = query(1, 1, n, l, r);
            if(full[x] != ' ') {
                int a = awal[kiri[x]], b = akhir[kiri[x]];
                pair<ll,ll> ret;
                if(kanan[y] == kiri[x]) ret = queryWord(1, 1, b-a+1, x-a+1, y-a+1, kiri[x]); // overlap in 1 word
                else ret = queryWord(1, 1, b-a+1, x-a+1, b-a+1, kiri[x]);
                ll bagi = power(p1, x-a, mod1);
                ret.first = ret.first * power(bagi, mod1-2, mod1);
                ret.first %= mod1;
                bagi = power(p2, x-a, mod2);
                ret.second = ret.second * power(bagi, mod2-2, mod2);
                ret.second %= mod2;
                if(mp[ret]) chaeng++;
            }
            if(full[y] != ' ' && kanan[y] != kiri[x]) {
                int a = awal[kanan[y]], b = akhir[kanan[y]];
                pair<ll,ll> ret = queryWord(1, 1, b-a+1, 1, y-a+1, kanan[y]);
                if(mp[ret]) chaeng++;
            }
            printf("%d\n", chaeng);
        } else {
            char c;
            scanf("%d %d %c",&x,&y,&c);
            int a = awal[x], b = akhir[x];
            updateWord(1, 1, b-a+1, y, c, x);
            update(1, 1, n, x, mp[segWord[x][1]]);
        }
    }
    return 0;
}
