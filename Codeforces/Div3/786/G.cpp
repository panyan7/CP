#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj, adj_rev;
vector<int> vis, anc, ord;

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
bool topological_sort() {
    //vis.assign(n, false);
    ord.clear();
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            bool res = dfs(i);
            if (!res)
                return false;
        }
    }
    reverse(ord.begin(), ord.end());
    return true;
}

void solve() {
    cin >> n >> m;
    adj.resize(n);
    adj_rev.resize(n);
    vis.assign(n, 0);
    anc.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    // first do topological sort
    topological_sort();
    // then do dp
    vector<int> dp(n, 1);
    for (int i = n-1; i >= 0; i--) {
        if (adj[ord[i]].size() > 1)
            for (int u : adj[ord[i]])
                if (adj_rev[u].size() > 1)
                    dp[ord[i]] = max(dp[ord[i]], dp[u] + 1);
    }
    int res = *max_element(dp.begin(), dp.end());
    cout << res << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
