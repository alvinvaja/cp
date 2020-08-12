/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = 1e12;
 
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};
 
struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
 
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
 
    void addEdge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }
 
    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }
 
    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
 
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
int arr[100100], l[1010], r[1010];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> n >> m;
    set<int> s;
    for(i=1;i<=n;i++) {
        cin >> arr[i];
        curr = arr[i];
        int akar = sqrt(curr);
        for(j=2;j<=akar;j++) {
            if(curr % j == 0) {
                while(curr % j == 0) curr /= j;
                s.insert(j);
            }
        }
        if(curr > 1) s.insert(curr);
    }
    for(i=1;i<=m;i++) {
        cin >> x >> y;
        if(x % 2 == 0) swap(x, y);
        l[i] = x;
        r[i] = y;
    }
    ll chaeng = 0;
    int src = n + 1, dest = n + 2; // dummy source and sink
    for(auto x : s) {
        Dinic dinic(n + 5, src, dest);
        for(i=1;i<=n;i++) {
            int power = 0;
            curr = arr[i];
            while(curr % x == 0) {
                curr /= x;
                power++;
            }
            if(i % 2 == 1) dinic.addEdge(src, i, power); // source to current vertex
            else dinic.addEdge(i, dest, power); // current vertex to sink
        }
        for(i=1;i<=m;i++) {
            dinic.addEdge(l[i], r[i], inf); // you can push from odd vertices to even vertices as many as possible
        }
        chaeng += dinic.flow();
    }
    cout << chaeng << endl;
    return 0;
}