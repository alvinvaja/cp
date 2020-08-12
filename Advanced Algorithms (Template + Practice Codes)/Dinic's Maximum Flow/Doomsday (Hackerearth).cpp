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

int arr[200200], dist[200200], visited[200200];
vector<pair<int,int> > vi[200200];

void resetDist(int n)
{
    for(int i = 1; i <= n; i++) dist[i] = 1e9, visited[i] = 0;
}

int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> n >> m >> k;
    int chaeng = 0;
    for(i=1;i<=n*2;i++) { // source = 1 to n, sink = n + 1 to n * 2
        cin >> arr[i];
        if(i <= n) chaeng += arr[i];
    }
    for(i=1;i<=m;i++) {
        int cost;
        cin >> x >> y >> cost;
        vi[x].push_back({y, cost});
        vi[y].push_back({x, cost});
    }

    int src = 2*n + 1, sink = 2*n + 2; // dummy source and sink
    Dinic dinic(2*n + 5, src, sink);
    for(i=1;i<=n;i++) dinic.addEdge(src, i, arr[i]);
    for(i=n+1;i<=2*n;i++) dinic.addEdge(i, sink, arr[i]);

    // find all possible other cities from every city i (1 to n)
    for(i=1;i<=n;i++) {
        int start = i;
        resetDist(n);
        set<pair<int,int> > s;
        dist[start] = 0;
        s.insert({dist[start], start});
        while(!s.empty()) {
            int node = (*s.begin()).second;
            s.erase(s.begin());
            if(visited[node]) continue;
            visited[node] = 1;
            for(auto x : vi[node]) {
                if(dist[x.first] > dist[node] + x.second) {
                    dist[x.first] = dist[node] + x.second;
                    s.insert({dist[x.first], x.first});
                }
            }
        }
        // push reachable cities to flow
        for(j=1;j<=n;j++) {
            if(dist[j] > k) continue; // not reachable under k minutes
            dinic.addEdge(start, j + n, inf); // you can push as many people as you need
        }
    }
    cout << chaeng - dinic.flow() << endl;
    return 0;
}
