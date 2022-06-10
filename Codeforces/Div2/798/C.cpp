#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<bool> vis;
vector<vector<int>> adj;
int res = INT_MAX;
vector<int> f;

void dfs(int v) {
    vis[v] = true;
    int child = 0;
    for (int u : adj[v])
        if (!vis[u])
            child++;
    if (child <= 1)
        res = min(res, f[v] + child);
    for (int u : adj[v]) {
        if (!vis[u]) {
            f[u] = f[v] + child;
            dfs(u);
        }
    }
}

void solve() {
    cin >> n;
    adj.clear();
    adj.resize(n);
    res = INT_MAX;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.assign(n, 0);
    f.assign(n, 0);
    f[0] = 1;
    dfs(0);
    cout << n-res << "\n";
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
