#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<int> vis, anc, ord, dist;

bool dfs(int v) {
    vis[v] = true;
    anc[v] = true;
    for (auto u : adj[v]) {
        if (!vis[u] && !dfs(u))
            return false;
        else if (anc[u])
            return false;
    }
    anc[v] = false;
    ord.push_back(v);
    return true;
}

int dfs_find(int v) {
    vis[v] = true;
    int res = 1;
    for (auto u : adj[v]) {
        if (!vis[u]) {
            dfs_find(u);
        }
        int rec = dist[u];
        if (v < u)
            rec++;
        res = max(rec, res);
    }
    dist[v] = res;
    return res;
}

// check long long
void solve() {
    cin >> n;
    adj.assign(n, vector<int>());
    vis.assign(n, 0);
    anc.assign(n, 0);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int v; cin >> v; v--;
            adj[i].push_back(v);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            if (!dfs(i)) {
                cout << -1 << "\n";
                return;
            }
    }
    vis.assign(n, 0);
    dist.assign(n, 0);
    reverse(ord.begin(), ord.end());
    for (int v: ord) {
        if (!vis[v]) {
            dfs_find(v);
        }
    }
    cout << *max_element(dist.begin(), dist.end()) << "\n";
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
