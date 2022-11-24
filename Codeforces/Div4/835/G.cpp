#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    int a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<vector<pll>> adj(n);
    for (int i = 0; i < n-1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> xa(n, 0), xb(n, 0);
    vector<bool> vis(n, 0);
    function<void(int,vector<ll>&,bool)> dfs = [&](int v, vector<ll>& x, bool s) {
        if (s && v == b)
            return;
        vis[v] = true;
        for (auto [u, w] : adj[v]) {
            if (!vis[u]) {
                x[u] = x[v] ^ w;
                dfs(u, x, s);
            }
        }
    };
    dfs(b, xb, false);
    vis.assign(n, 0);
    dfs(a, xa, true);
    set<ll> st;
    if (xa[b] == 0) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i])
            st.insert(xa[i]);
    }
    for (int i = 0; i < n; i++) {
        if (i != b && st.find(xb[i]) != st.end()) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
