/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a,b;
ll suma, sumb, chaeng;
vector<int> vi[500500];
ll dpa[500500], dpb[500500];
int p[500500];
void dfs(int now, int level)
{
    dpa[now]++;
    p[level] = now;
    for(auto x : vi[now]) {
        dfs(x, level+1);
    }
    if(level >= a) {
        dpa[p[level-a]] += dpa[now];
    }
}
void rec(int now, int level)
{
    dpb[now]++;
    p[level] = now;
    for(auto x : vi[now]) {
        rec(x, level+1);
    }
    if(level >= b) {
        dpb[p[level-b]] += dpb[now];
    }
}
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> tc;
    int inc = 1;
    while(tc--)
    {
        cin >> n >> a >> b;
        for(i=0;i<=n;i++) vi[i].clear(), dpa[i] = 0, dpb[i] = 0;
        for(i=2;i<=n;i++) {
            scanf("%d",&curr);
            vi[curr].push_back(i);
        }
        for(i=1;i<=n;i++) p[i] = 0;
        dfs(1, 0);
        for(i=1;i<=n;i++) p[i] = 0;
        rec(1, 0);
        chaeng = 0;
        for(i=1;i<=n;i++) chaeng += 1LL*dpa[i]*n;
        for(i=1;i<=n;i++) chaeng += 1LL*dpb[i]*n;
        for(i=1;i<=n;i++) chaeng -= 1LL*dpa[i]*dpb[i];
        double sana = chaeng / (double) (1LL*n*n);
        printf("Case #%d: %.9f\n", inc++, sana);
    }
    return 0;
}
