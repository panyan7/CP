#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
 
struct FlowEdge {
    int u, v;
    ll cap, cost, flow = 0;
    FlowEdge(int u, int v, ll cap, ll cost) : u(u), v(v), cap(cap), cost(cost) {}
};
 
struct MinCostFlow {
    vector<vector<int>> adj;
    vector<FlowEdge> edges;
    vector<pll> ans;
    const ll INF = 1e18;
    int n, m = 0;
    int s, t;
    MinCostFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.assign(n, vector<int>());
    }
    void add_edge(int u, int v, ll cap_, ll cost_) {
        edges.emplace_back(u, v, cap_, cost_);
        edges.emplace_back(v, u, 0, -cost_);
        adj[u].push_back(m);
        adj[v].push_back(m+1);
        m += 2;
    }
    void shortest_path(int v0, vector<ll>& d, vector<int>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, 0);
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
    ll flow(ll k = -1) {
        if (k == -1) k = INF;
        ll flow = 0, cost = 0;
        vector<ll> d;
        vector<int> p;
        while (flow < k) {
            shortest_path(s, d, p);
            if (d[t] == INF)
                break;
            ll f = k - flow;
            int cur = t;
            while (cur != s) {
                f = min(f, edges[p[cur]].cap);
                cur = edges[p[cur]].u;
            }
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
        if (k < INF && flow < k)
            return -1;
        else
            return cost;
    }
};
 
 
ll a[55][55], b[55][55], c[55][55], d[55][55];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j] >> b[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j] >> d[i][j];
    ll res = 1e18;
    int s = 4*n, t = 4*n+1;
    vector<int> g(n), r(n);
    int best_h = 0;
    for (int h = 0; h <= n; h++) {
        MinCostFlow G(4*n+2, s, t);
        for (int i = 0; i < n; i++)
            G.add_edge(s, i, 1, 0);
        for (int i = 0; i < n; i++)
            G.add_edge(i+3*n, t, 1, 0);
        for (int i = 0; i < n; i++) {
            G.add_edge(i+n, i+2*n, 1, 0);
            for (int j = 0; j < h; j++) {
                G.add_edge(i, j+n, 1, a[i][j]);
                G.add_edge(j+2*n, i+3*n, 1, c[i][j]);
            }
            for (int j = h; j < n; j++) {
                G.add_edge(i, j+n, 1, b[i][j]);
                G.add_edge(j+2*n, i+3*n, 1, d[i][j]);
            }
        }
        ll f = G.flow(n);
        res = min(res, f);
        if (res == f) {
            best_h = h;
            for (auto& e : G.edges) {
                if (e.u < n && e.v >= n && e.v < 2*n && e.flow > 0) {
                    g[e.u] = e.v - n;
                }
                if (e.u >= 2*n && e.u < 3*n && e.v >= 3*n && e.v < 4*n && e.flow > 0) {
                    r[e.u-2*n] = e.v - 3*n;
                }
            }
        }
    }
    cout << res << "\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << " " << g[i]+1 << (g[i] < best_h ? "A" : "B") << " " << r[g[i]]+1 << "\n";
    }
}
