#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<vector<pii>> adj(n, vector<pii>());
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<bool> vis(n, 0);
    bool can = true;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 2) {
            cout << "-1\n";
            return;
        }
    }
    vector<int> res(n-1, -1);
    function<void(int, bool)> dfs = [&](int v, bool two) {
        vis[v] = 1;
        for (auto p : adj[v]) {
            if (!vis[p.first]) {
                if (two) {
                    res[p.second] = 2;
                } else {
                    res[p.second] = 5;
                }
                dfs(p.first, !two);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1 && !vis[i]) {
            dfs(i, true);
        }
    }
    for (int i = 0; i < n-1; i++) {
        cout << res[i] << " ";
    }
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
