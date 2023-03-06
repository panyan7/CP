#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

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

int tt = 1, n, m;

void solve() {
    cin >> n >> m;
    vector<bitset<501>> a(m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            a[j][i] = s[j] - '0';
    }
    int s = 2*m, t = 2*m+1;
    MaxFlow G(2*m+2, s, t);
    for (int i = 0; i < m; i++) {
        G.add_edge(s, i, 1);
        for (int j = 0; j < m; j++) {
            if ((a[i] & a[j]) == a[j] && (a[i] != a[j] || i < j))
                G.add_edge(i, m+j, 1);
        }
        G.add_edge(i+m, t, 1);
    }
    cout << m - G.flow() << "\n";
    vector<int> parent(m, -1);
    for (auto& e : G.edges) {
        if (0 <= e.u && e.u < m && m <= e.v && e.v < 2*m && e.flow > 0) {
            parent[e.v-m] = e.u;
        }
    }
    vector<int> doc_level(m, 0);
    vector<int> group(m, 0);
    int k = 0;
    auto dfs = [&](auto dfs, int v) -> void {
        if (doc_level[v] > 0)
            return;
        if (parent[v] == -1) {
            doc_level[v] = 1;
            group[v] = k;
            k++;
            return;
        }
        dfs(dfs, parent[v]);
        doc_level[v] = doc_level[parent[v]] + 1;
        group[v] = group[parent[v]];
    };
    for (int i = 0; i < m; i++)
        dfs(dfs, i);
    for (int i = 0; i < m; i++)
        cout << group[i]+1 << " ";
    cout << "\n";
    for (int i = 0; i < m; i++)
        cout << doc_level[i]+1 << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) {
        vector<int> dev_level(k, 0);
        for (int j = 0; j < m; j++) {
            if (a[j][i]) {
                dev_level[group[j]] = max(dev_level[group[j]], doc_level[j]);
            }
        }
        for (int i = 0; i < k; i++)
            cout << dev_level[i]+1 << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
