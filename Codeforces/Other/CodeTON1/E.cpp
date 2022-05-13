#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<int> res;
vector<bool> vis;

void dfs(int v, bool neg) {
    vis[v] = true;
    res[v] = (int)adj[v].size();
    if (neg)
        res[v] = -res[v];
    for (int u : adj[v])
        if (!vis[u])
            dfs(u, !neg);
}

void solve() {
    cin >> n;
    adj.clear();
    adj.resize(n);
    vis.assign(n, 0);
    res.assign(n, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, false);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
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
