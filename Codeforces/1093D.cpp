#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int odd, bipartite, jml;
vector<int> vi[300100];
int color[300100];
int visited[300100];
void dfs(int node, int prev)
{
    if(visited[node] == 0)
    {
        if(color[node] == 0)
            odd++;
        jml++;
    }
    
    visited[node] = 1;
    int i,temp;
    for(i=0;i<vi[node].size();i++)
    {
        temp = vi[node][i];
        if(temp == prev)
            continue;
        if(color[temp] == -1)
        {
            color[temp] = 1 - color[node];
            dfs(temp,node);
        }
        else if(color[temp] == color[node])
        {
            bipartite = 0;
        }
    }
}

long long int power(long long int a, long long int b)
{
    long long int ret = 1;
    if(b == 0)
        return ret;
    else
    {
        while(b > 0)
        {
            if(b%2==1)
            {
                ret = (ret*a) % mod;
            }
            a = (a*a) % mod;
            b = b / 2;
        }
        return ret % mod;
    }
}
int main()
{
    int tc,i,j,k,curr,n,m,x,y;
    scanf("%d",&tc);
    for(i=0;i<tc;i++)
    {
        scanf("%d %d",&n,&m);
        odd = 0;
        bipartite = 1;
        for(j=1;j<=n;j++)
        {
            color[j] = -1;
            visited[j] = 0;
            vi[j].clear();
        }
        for(j=0;j<m;j++)
        {
            scanf("%d %d",&x,&y);
            vi[x].push_back(y);
            vi[y].push_back(x);
        }
        long long int ans = 1;
        for(j=1;j<=n;j++)
        {
            odd = jml = 0;
            if(visited[j] == 0)
            {
                color[j] = 0;
                dfs(j,j);
                long long int tempo = (power(2,odd) + power(2,jml-odd)) % mod;
                ans = (ans * tempo) % mod;
            }
        }
        if(bipartite == 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n",ans);
        }
    }
    return 0;
}
