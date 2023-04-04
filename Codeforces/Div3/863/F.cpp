#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k = sqrt(n);
    if (k <= 2 || k * k != n) {
        cout << "NO\n";
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() != 2 && adj[i].size() != 4) {
            cout << "NO\n";
            return;
        }
        if (adj[i].size() == 4)
            cnt++;
    }
    if (cnt != k) {
        cout << "NO\n";
        return;
    }
    vector<bool> vis(n, false), anc(n, false);
    cnt = 0;
    auto dfs = [&](auto dfs, int v) -> void {
        vis[v] = true;
        cnt++;
        for (int u : adj[v]) {
            if (adj[u].size() == 4 && !vis[u]) {
                dfs(dfs, u);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 4) {
            dfs(dfs, i);
            break;
        }
    }
    if (cnt != k) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        int cur = 0;
        if (adj[i].size() == 4) {
            for (int u : adj[i]) {
                if (adj[u].size() == 4)
                    cur++;
            }
            if (cur != 2) {
                cout << "NO\n";
                return;
            }
        }
    }
    bool ok = true;
    auto dfs2 = [&](auto dfs2, int v, int p) -> void {
        vis[v] = true;
        cnt++;
        for (int u : adj[v]) {
            if (v != p && adj[u].size() == 4 && u != p)
                ok = false;
            if (!vis[u]) {
                dfs2(dfs2, u, p);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 4) {
            cnt = 0;
            dfs2(dfs2, i, i);
            if (cnt != k) {
                cout << "NO\n";
                return;
            }
        }
    }
    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
