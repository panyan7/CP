#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct FlowEdge {
    int u, v;
    long long cap, cost, flow = 0;
    FlowEdge(int u, int v, long long cap, long long cost) : u(u), v(v), cap(cap), cost(cost) {}
};
struct MinCostFlow {
    vector<vector<int>> adj, cost, cap;
    vector<FlowEdge> edges;
    vector<pll> ans;
    const long long INF = 1e14;
    int n, m = 0;
    int s, t;
    MinCostFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.assign(n, vector<int>());
    }
    void add_edge(int u, int v, long long cap_, long long cost_) {
        edges.emplace_back(u, v, cap_, cost_);
        edges.emplace_back(v, u, 0, -cost_);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    void shortest_paths(int v0, vector<long long>& d, vector<int>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(v0);
        p.assign(n, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int id : adj[u]) {
                int v = edges[id].v;
                if (edges[id].cap > 0 && d[v] > d[u] + edges[id].cost) {
                    d[v] = d[u] + edges[id].cost;
                    p[v] = id;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    pair<long long, long long> flow() {
        long long flow = 0;
        long long cost = 0;
        vector<long long> d;
        vector<int> p;
        while (flow < INF) {
            shortest_paths(s, d, p);
            if (d[t] == INF)
                break;
            // find max flow on that path
            long long f = k - flow;
            int cur = t;
            while (cur != s) {
                f = min(f, edges[p[cur]].cap);
                cur = edges[p[cur]].u;
            }
            // apply flow
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s) {
                edges[p[cur]].flow += f;
                edges[p[cur]^1].flow -= f;
                edges[p[cur]].cap -= f;
                edges[p[cur]^1].cap += f;
                cur = edges[p[cur]].u;
            }
            ans.push_back({flow, cost});
        }
        return {flow, cost};
    }
};

int tt = 1, n, m, k;
ll a[505];
vector<vector<int>> adj;

// check long long
void solve() {
    ll x, y;
    cin >> n >> x >> y;
    x--, y--;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MinCostFlow G(3*n+2, 3*n, 3*n+1);
    ll cnt = 0;
    vector<int> parent(n, -1);
    vector<int> vis(n, 0);
    vector<ll> ports(n, -1), ports2(n, -1);
    auto bfs = [&](int s) {
        parent.assign(n, -1);
        vis.assign(n, 0);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (!vis[u]) {
                    vis[u] = 1;
                    q.push(u);
                    parent[u] = v;
                }
            }
        }
    };
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pii> edges2;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges2.emplace_back(u, v);
    }
    int q1; cin >> q1;
    for (int i = 0; i < q1; i++) {
        ll c, d;
        cin >> c >> d;
        c--;
        ports[c] = d;
    }
    bfs(x);
    for (int i = 0; i < n; i++) {
        int pr = (parent[i] == -1 ? 3*n : parent[i]);
        if (ports[i] == -1)
            G.add_edge(pr, i, G.INF, 0);
        else {
            G.add_edge(pr, i, ports[i], -1e8);
            cnt += ports[i];
        }
        G.add_edge(i, i+n, 1, -a[i]);
    }
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u = edges2[i].first, v = edges2[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q2; cin >> q2;
    for (int i = 0; i < q2; i++) {
        ll c, d;
        cin >> c >> d;
        c--;
        ports2[c] = d;
    }
    bfs(y);
    for (int i = 0; i < n; i++) {
        int pr = (parent[i] == -1 ? 3*n+1 : parent[i]+2*n);
        if (ports2[i] == -1)
            G.add_edge(i+2*n, pr, G.INF, 0);
        else {
            G.add_edge(i+2*n, pr, ports2[i], -1e8);
            cnt += ports2[i];
        }
        G.add_edge(i+n, i+2*n, G.INF, 0);
    }
    pll res = G.flow();
    res.second += cnt*1e8;
    for (int i = 0; i < G.m; i += 2) {
        auto edge = G.edges[i];
        int u = edge.u, v = edge.v;
        if (v < n) {
            if (ports[v] != -1 && edge.flow != ports[v]) {
                cout << "-1\n";
                return;
            }
        }
        if (u >= 2*n && u < 3*n) {
            if (ports2[u-2*n] != -1 && edge.flow != ports2[u-2*n]) {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << -res.second << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
