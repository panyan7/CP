#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<int> vis;
vector<vector<int>> adj;
vector<ll> h, mx;

pll dfs(int v) {
    vis[v] = true;
    ll mxx = 0, idx = v;
    for (int u : adj[v]) {
        if (!vis[u]) {
            pll r = dfs(u);
            if (r.first > mxx) {
                mxx = max(mxx, r.first);
                idx = r.second;
            }
        }
    }
    if (h[v] > mxx) {
        mx[idx] = h[v];
        mxx = max(mxx, h[v]);
    }
    return {mxx, idx};
}

// check long long
void solve() {
    cin >> n;
    adj.resize(n);
    vis.assign(n, 0);
    mx.assign(n, 0);
    h.assign(n, 0);
    ll mxh = 0;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1)
            mxh = max(h[i], mxh);
    }
    pll r;
    for (int i = 0; i < n; i++) {
        if (h[i] == mxh) {
            r = dfs(i);
            mx[i] = r.first;
            break;
        }
    }
    mx.assign(n, 0);
    vis.assign(n, 0);

    int i = r.second;
    r = dfs(i);
    mx[i] = r.first;
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += mx[i];
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
