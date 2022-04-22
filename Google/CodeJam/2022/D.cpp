#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<bool> vis;
vector<ll> f;
vector<pll> res;

void dfs(int v) {
    vis[v] = true;
    if (adj[v].size() == 0) {
        res[v] = {f[v], f[v]};
        return;
    }
    ll total = 0;
    ll mn = LLONG_MAX;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u);
            mn = min(mn, res[u].first);
            total += res[u].second;
        }
    }
    if (f[v] > mn) {
        total = total - mn + f[v];
        mn = f[v];
    }
    res[v] = {mn, total};
}

void solve() {
    cin >> n;
    f.assign(n+1, 0);
    res.assign(n+1, {0,0});
    adj.clear();
    adj.resize(n+1);
    vis.assign(n+1, false);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        adj[u].push_back(i);
    }
    dfs(0);
    cout << res[0].second << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    for (int t1 = 1; t1 <= tt; t1++) {
        cout << "Case #" << t1 << ": ";
        solve();
    }
    return 0;
}
