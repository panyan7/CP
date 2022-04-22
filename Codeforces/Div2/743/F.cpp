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
    //vector<pii> ans;
    const long long INF = 1e14;
    int n, m = 0;
    int s, t;
    long long k;
    MinCostFlow(int n, long long k, int s, int t) : n(n), k(k), s(s), t(t) {
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
    long long flow() {
        long long flow = 0;
        long long cost = 0;
        vector<long long> d;
        vector<int> p;
        while (flow < k) {
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
                edges[p[cur]].cap -= f;
                edges[p[cur]^1].cap += f;
                cur = edges[p[cur]].u;
            }
            //ans.push_back({flow, cost});
        }
        return cost;
        /*
        if (flow < k)
            return -1;
        else
            return cost;
            */
    }
};

int tt = 1, n, m, k;

void solve() {
    // bitmasks of 1 bit and 2 bits
    cin >> n >> k;
    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    vector<pii> es;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < (1 << n); x++) {
            int z = x;
            int y = x ^ (1 << i);
            if (z < y)
                es.push_back({z, y});
        }
    }
    vector<pair<int,pii>> edges;
    for (auto p : es) {
        edges.push_back({a[p.first] + a[p.second], p});
    }

    int N = min((int)edges.size(), 20000);
    nth_element(edges.begin(), edges.begin()+N-1, edges.end(), greater<pair<int,pii>>());

    vector<pii> final_edges;
    for (int i = 0; i < N; i++) {
        final_edges.push_back(edges[i].second);
    }
    vector<int> id(1 << n, -1);
    int j = 0;
    for (pii e : final_edges) {
        if (id[e.first] == -1)
            id[e.first] = j++;
        if (id[e.second] == -1)
            id[e.second] = j++;
    }

    MinCostFlow G(j + 4, k, j, j + 3);
    G.add_edge(j, j + 1, k, 0);
    G.add_edge(j + 2, j + 3, k, 0);
    vector<bool> used(1 << n, 0);
    for (pii e : final_edges) {
        int c = __builtin_popcount(e.first);
        if (c % 2 == 0)
            G.add_edge(id[e.first], id[e.second], 1, 0);
        else
            G.add_edge(id[e.second], id[e.first], 1, 0);
    }
    for (int i = 0; i < (1 << n); i++) {
        if (id[i] == -1)
            continue;
        int c = __builtin_popcount(i);
        if (c % 2 == 0)
            G.add_edge(j + 1, id[i], 1, -a[i]);
        else
            G.add_edge(id[i], j + 2, 1, -a[i]);
    }
    ll res = G.flow();
    cout << -res << "\n";
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
