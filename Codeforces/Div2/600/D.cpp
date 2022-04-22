#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v, int& mx, int& mn) {
    visited[v] = true;
    mx = max(v, mx);
    mn = min(v, mn);
    for (int u : adj[v])
        if (!visited[u])
            dfs(u, mx, mn);
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vector<int> (0));
    visited.assign(n, false);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<array<int,2>> comp;
    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            int mx = -1, mn = INT_MAX;
            dfs(v, mx, mn);
            comp.push_back({mn, mx});
        }
    }
    sort(all(comp));
    int cnt = 0, mx = -1;
    for (auto p : comp) {
        if (p[0] < mx) ++cnt;
        mx = max(mx, p[1]);
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
