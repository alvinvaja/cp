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
char tampung[1000010];
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
    }
    int mid = (l+r) / 2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);

    int mix = min(segtree[idx*2].open, segtree[idx*2+1].close);
    segtree[idx].match = segtree[idx*2].match + segtree[idx*2+1].match + mix;
    segtree[idx].open = segtree[idx*2].open + segtree[idx*2+1].open - mix;
    segtree[idx].close = segtree[idx*2].close + segtree[idx*2+1].close - mix;
}

struct bracket update(int idx, int l, int r, int carix, int cariy)
{
    if(l >= carix && r <= cariy)
    {
        return segtree[idx];
    }
    else if(l > cariy || r < carix)
    {
        struct bracket temp;
        temp.open = 0;
        temp.close = 0;
        temp.match = 0;
        return temp;
    }
    struct bracket left,right,hasil;
    int mid = (l+r)/2;
    left = update(idx*2,l,mid,carix,cariy);
    right = update(idx*2+1,mid+1,r,carix,cariy);

    int mix = min(left.open, right.close);
    hasil.match = left.match + right.match + mix;
    hasil.open = left.open + right.open - mix;
    hasil.close = left.close + right.close - mix;
    return hasil;
}
int main()
{
    int i,j,k,x,y,ans,curr,temp;
    scanf("%s",tampung);
    int n = strlen(tampung);
    for(i=0;i<n;i++)
    {
        arr[i+1] = tampung[i];
    }
    int query;
    scanf("%d",&query);
    build(1,1,n);
    for(i=1;i<=query;i++)
    {
        scanf("%d %d",&x,&y);
        struct bracket jwb;
        jwb = update(1,1,n,x,y);
        printf("%d\n",jwb.match*2);
    }
    return 0;
}
