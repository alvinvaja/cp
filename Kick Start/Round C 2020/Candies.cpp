/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[200200];
ll segtree[600600][2];
ll pref[600600][2];
void build(int idx, int l, int r)
{
    if(l == r) {
        if(l%2==1) {
            segtree[idx][0] = -1LL*l*arr[l];
            segtree[idx][1] = 1LL*l*arr[l];
            pref[idx][0] = -arr[l];
            pref[idx][1] = arr[l];
        } else {
            segtree[idx][0] = 1LL*l*arr[l];
            segtree[idx][1] = -1LL*l*arr[l];
            pref[idx][0] = arr[l];
            pref[idx][1] = -arr[l];
        }
        return;
    }
    int mid = (l+r) / 2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    segtree[idx][0] = segtree[idx*2][0] + segtree[idx*2+1][0];
    segtree[idx][1] = segtree[idx*2][1] + segtree[idx*2+1][1];
    pref[idx][0] = pref[idx*2][0] + pref[idx*2+1][0];
    pref[idx][1] = pref[idx*2][1] + pref[idx*2+1][1];
}
void update(int idx, int l, int r, int index, int val)
{
    if(l > index || r < index) return;
    if(l == r && l == index) {
        if(l%2==1) {
            segtree[idx][0] = -1LL*l*val;
            segtree[idx][1] = 1LL*l*val;
            pref[idx][0] = -val;
            pref[idx][1] = val;
        } else {
            segtree[idx][0] = 1LL*l*val;
            segtree[idx][1] = -1LL*l*val;
            pref[idx][0] = val;
            pref[idx][1] = -val;
        }
        return;
    }
    int mid = (l+r) / 2;
    update(idx*2, l, mid, index, val);
    update(idx*2+1, mid+1, r, index, val);
    segtree[idx][0] = segtree[idx*2][0] + segtree[idx*2+1][0];
    segtree[idx][1] = segtree[idx*2][1] + segtree[idx*2+1][1];
    pref[idx][0] = pref[idx*2][0] + pref[idx*2+1][0];
    pref[idx][1] = pref[idx*2][1] + pref[idx*2+1][1];
}
ll queryAdd(int idx, int l, int r, int kiri, int kanan)
{
    if(l > kanan || r < kiri) return 0;
    if(l >= kiri && r <= kanan) {
        if(kiri%2==0) {
            return segtree[idx][0];
        } else {
            return segtree[idx][1];
        }
    }
    int mid = (l+r) / 2;
    ll sum = queryAdd(idx*2, l, mid, kiri, kanan);
    sum += queryAdd(idx*2+1, mid+1, r, kiri, kanan);
    return sum;
}
ll querySub(int idx, int l, int r, int kiri, int kanan)
{
    if(l > kanan || r < kiri) return 0;
    if(l >= kiri && r <= kanan) {
        if(kiri%2==0) {
            return pref[idx][0];
        } else {
            return pref[idx][1];
        }
    }
    int mid = (l+r) / 2;
    ll sum = querySub(idx*2, l, mid, kiri, kanan);
    sum += querySub(idx*2+1, mid+1, r, kiri, kanan);
    return sum;
}
int main()
{
    int n,i,j,k,x,y,ans,curr,m;
    int tc;
    int inc = 1;
    cin >> tc;
    while(tc--)
    {
        int q;
        cin >> n >> q;
        for(i=1;i<=n;i++) {
            scanf("%lld",&arr[i]);
        }
        ll chaeng = 0;
        build(1, 1, n);
        while(q--) {
            char c;
            getchar();
            scanf("%c %d %d",&c,&x,&y);
            if(c == 'U') {
                update(1, 1, n, x, y);
            } else {
                ll now = queryAdd(1, 1, n, x, y);
                now -= 1LL*(x-1)*querySub(1, 1, n, x, y);
                chaeng += now;
            }
        }
        printf("Case #%d: %lld\n", inc++, chaeng);
    }
	return 0;
}
