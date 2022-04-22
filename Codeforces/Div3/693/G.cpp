#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> c(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }
    queue<int> q;
    vector<int> vis(n, 0);
    vector<int> d(n, 1e9);
    vis[0] = true;
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        c[i] = d[i];
    }
    vis.assign(n, 0);
    function<void(int)> dfs = [&](int v) {
        vis[v] = true;
        for (int u : adj[v]) {
            if (d[u] <= d[v]) {
                c[v] = min(c[v], d[u]);
                continue;
            }
            if (!vis[u])
                dfs(u);
            c[v] = min(c[v], c[u]);
        }
    };
    dfs(0);
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
