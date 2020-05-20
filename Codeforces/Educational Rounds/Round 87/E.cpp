/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool visited[100100];
int color[100100];
bool can;
int dp[5050][5050];
int cnt[2];
vector<int> sana[2];
vector<int> vi[5050];
int comp;
int arr[5050][2];
int a,b,c;
struct angka
{
    vector<int> sana[2];
    int cnt[2];
};
struct angka node[5050];
bool desc(struct angka a, struct angka b)
{
    return a.sana[0].size() + a.sana[1].size() > b.sana[0].size() + b.sana[1].size();
}
int rec(int pos, int sum)
{
    if(sum > b) return 0;
    if(pos == comp) {
        if(sum == b) return dp[pos][sum] = 1;
        else return dp[pos][sum] = 0;
    }
    if(dp[pos][sum] != -1) return dp[pos][sum];
    int now = 0;
    now |= rec(pos+1, sum+node[pos+1].cnt[0]);
    now |= rec(pos+1, sum+node[pos+1].cnt[1]);
    return dp[pos][sum] = now;
}
void dfs(int now, int col)
{
    visited[now] = 1;
    cnt[col]++;
    sana[col].push_back(now);
    color[now] = col;
    for(auto x : vi[now]) {
        if(visited[x]) {
            if(color[x] == color[now]) can = 0;
            continue;
        }
        dfs(x, col ^ 1);
    }
}
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    cin >> n >> m;
    cin >> a >> b >> c;
    for(i=1;i<=m;i++) {
        cin >> x >> y;
        vi[x].push_back(y);
        vi[y].push_back(x);
    }
    memset(color, -1, sizeof(color));
    comp = 1;
    for(i=1;i<=n;i++) {
        if(visited[i]) continue;
        can = 1;
        cnt[0] = cnt[1] = 0;
        sana[0].clear();
        sana[1].clear();
        dfs(i, 0);
        for(j=0;j<2;j++) node[comp].cnt[j] = cnt[j];
        for(j=0;j<2;j++) node[comp].sana[j].swap(sana[j]);
        comp++;
        if(!can) {
            printf("NO\n");
            return 0;
        }
    }
    sort(node+1, node+comp, desc);
    memset(dp, -1, sizeof(dp));
    rec(0, 0);
    if(!dp[0][0]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int chaeng[5050];
    for(i=1;i<=n;i++) chaeng[i] = 1;
    int now = 0;
    for(i=0;i<comp;i++) {
        for(j=0;j<2;j++) {
            arr[i+1][j] = node[i+1].cnt[j];
            if(now + arr[i+1][j] <= b && dp[i+1][now + arr[i+1][j]]) {
                now += arr[i+1][j];
                for(auto x : node[i+1].sana[j]) {
                    chaeng[x] = 2;
                }
                break;
            }
        }
    }
    for(i=1;i<=n;i++) {
        if(chaeng[i] == 1 && c > 0) {
            c--;
            chaeng[i] += 2;
        }
    }
    for(i=1;i<=n;i++) cout << chaeng[i];
    cout << endl;
    return 0;
}
