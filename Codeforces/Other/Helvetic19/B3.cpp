#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

const ll INF = 1e18;

// Dinic's algorithm for max flow
struct FlowEdge {
    int u, v;
    long long cap, flow = 0;
    FlowEdge(int u, int v, long long cap) : u(u), v(v), cap(cap) {}
};
struct MaxFlow {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    MaxFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u, int v, long long cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].v] != -1)
                    continue;
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int u, long long pushed) {
        if (pushed == 0)
            return 0;
        if (u == t)
            return pushed;
        for (int& cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
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

ll tt = 1, n, m, s, b, k, h;

void solve() {
    cin >> n >> m;
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u == v)
            continue;
        d[u][v] = 1;
        d[v][u] = 1;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cin >> s >> b >> k;
    vector<ll> x(s, 0), a(s, 0), f(s, 0), p(s, 0);
    for (int i = 0; i < s; i++) {
        cin >> x[i] >> a[i] >> f[i] >> p[i];
        x[i]--;
    }
    vector<ll> y(b, 0), df(b, 0), g(b, 0);
    for (int i = 0; i < b; i++) {
        cin >> y[i] >> df[i] >> g[i];
        y[i]--;
    }
    vector<bool> in_dep(s, 0);
    vector<bool> out_dep(s, 0);
    vector<pair<int,int>> dep(k);
    for (int i = 0; i < k; i++) {
        cin >> dep[i].first >> dep[i].second;
        dep[i].first--, dep[i].second--;
        in_dep[dep[i].first] = true;
        out_dep[dep[i].second] = true;
    }
    ll res = 0;
    vector<ll> max_gold(s, -INF);
    vector<int> index;
    vector<int> index_rev(s, -1);
    int cur_id = 0;
    vector<vector<pll>> best_g(n);
    for (int j = 0; j < b; j++) {
        best_g[y[j]].push_back({df[j], g[j]});
    }
    for (int j = 0; j < n; j++)
        sort(best_g[j].begin(), best_g[j].end(), greater<pll>());
    for (int j = 0; j < n; j++) {
        ll mx = -INF;
        for (int i = (int)best_g[j].size()-1; i >= 0; i--) {
            mx = max(mx, best_g[j][i].second);
            best_g[j][i].second = mx;
        }
    }
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < n; j++) {
            if (d[x[i]][j] <= f[i]) {
                auto it = lower_bound(best_g[j].begin(), best_g[j].end(), (pll){a[i], INF}, greater<pll>());
                if (it != best_g[j].end())
                    max_gold[i] = max(max_gold[i], it->second);
            }
        }
        max_gold[i] -= p[i];
        if (!in_dep[i] && !out_dep[i]) {
            if (max_gold[i] >= 0)
                res += max_gold[i];
        } else {
            index_rev[i] = index.size();
            index.push_back(i);
        }
    }
    assert(index.size() <= 2 * k);
    MaxFlow G(index.size()+2, index.size(), index.size()+1);
    ll total = 0;
    for (int j = 0; j < index.size(); j++) {
        int i = index[j];
        if (!in_dep[i] && !out_dep[i])
            continue;
        if (max_gold[i] >= 0)
            total += max_gold[i];
        if (max_gold[i] >= 0) {
            G.add_edge(index.size(), j, max_gold[i]);
        } else {
            G.add_edge(j, index.size()+1, -max_gold[i]);
        }
    }
    for (int i = 0; i < k; i++) {
        if (index_rev[dep[i].first] != -1 && index_rev[dep[i].second] != -1)
            G.add_edge(index_rev[dep[i].first], index_rev[dep[i].second], G.flow_inf);
    }
    ll fl = G.flow();
    total -= fl;
    res += total;
    cout << res << "\n";
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
