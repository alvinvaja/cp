#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,curr,m,temp,x,y;
    scanf("%d %d",&n,&m);
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int awal = x1;
    int akhir = x2;
    int l = y1;
    int r = y2;
    int ans = 0;
    for(i=1;i<=n;i++)
    {
        if(i >= awal && i <= akhir)
        {
            curr = l - 1;
            if(curr % 2 == 1)
                ans++;
            curr = m - r;
            if(curr % 2 == 1)
                ans++;
        }
        else
        {
            if(m % 2 == 1)
                ans++;
        }
    }
    if(ans % 2 == 1)
    {
        ans = (ans / 2) + 1;
    }
    else
    {
        ans = ans / 2;
    }
    printf("%d\n",ans);
    return 0;
}
