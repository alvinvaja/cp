#include<bits/stdc++.h>
using namespace std;
struct bracket
{
    int match;
    int open;
    int close;
};
struct bracket segtree[4000040];
char arr[1000010];
int valid;
void build(int idx, int l, int r)
{
    if(l == r)
    {
        if(arr[l] == '(')
        {
            segtree[idx].open = 1;
            segtree[idx].close = 0;
            segtree[idx].match = 0;
        }
        else
        {
            segtree[idx].open = 0;
            segtree[idx].close = 1;
            segtree[idx].match = 0;
        }
        return;
        //aaaaa
    }
    int mid = (l+r) / 2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);

    int mix = min(segtree[idx*2].open, segtree[idx*2+1].close);
    segtree[idx].match = segtree[idx*2].match + segtree[idx*2+1].match + mix;
    segtree[idx].open = segtree[idx*2].open + segtree[idx*2+1].open - mix;
    segtree[idx].close = segtree[idx*2].close + segtree[idx*2+1].close - mix;
}

void update(int idx, int l, int r, int cari, char diff)
{
    if(l > cari || r < cari)
        return;
    if(l == r && l == cari)
    {
        if(diff == '(')
        {
            segtree[idx].open = 0;
            segtree[idx].close = 1;
            segtree[idx].match = 0;
        }
        else
        {
            segtree[idx].open = 1;
            segtree[idx].close = 0;
            segtree[idx].match = 0;
        }
        return;
    }
    int mid = (l+r)/2;
    update(idx*2,l,mid,cari,diff);
    update(idx*2+1,mid+1,r,cari,diff);

    int mix = min(segtree[idx*2].open, segtree[idx*2+1].close);
    segtree[idx].match = segtree[idx*2].match + segtree[idx*2+1].match + mix;
    segtree[idx].open = segtree[idx*2].open + segtree[idx*2+1].open - mix;
    segtree[idx].close = segtree[idx*2].close + segtree[idx*2+1].close - mix;
}
int main()
{
    int n,i,j,k,x,y,ans,curr,temp;
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++)
    {
        scanf("%c",&arr[i]);
    }
    if(n%2==1)
    {
        printf("0\n");
        return 0;
    }
    build(1,1,n);
    ans = 0;
    for(i=1;i<=n;i++)
    {
        if(arr[i] == '(')
        {
            update(1,1,n,i,'(');
            if(segtree[1].open == segtree[1].close && segtree[1].open == 0)
                ans++;
            update(1,1,n,i,')');
        }
        else
        {
            update(1,1,n,i,')');
            if(segtree[1].open == segtree[1].close && segtree[1].open == 0)
                ans++;
            update(1,1,n,i,'(');
        }
    }
    printf("%d\n",ans);
    return 0;
}
