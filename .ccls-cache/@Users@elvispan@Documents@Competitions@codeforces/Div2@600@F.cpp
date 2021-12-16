#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(c) (c).begin(), (c).end()

int t = 1, n, m, k, q;
vector<vector<pii>> adj;
vector<int> dist;

void solve() {
    cin >> n >> m >> k >> q;
    adj.reserve(n);
    dist.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pii> pq;
    for (int v = 0; v < k; ++v)
        pq.push({0, v});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d != dist[v])
            continue;
        for (auto [u, w] : adj[v]) {
            if (dist[v]+w < dist[u]) {
                dist[u] = dist[v]+w;
                pq.push({dist[u], u});
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
