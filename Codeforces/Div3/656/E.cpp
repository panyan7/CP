#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<int> ord, vis, anc;

bool dfs(int v) {
    vis[v] = true;
    anc[v] = true;
    for (int u : adj[v]) {
        if (!vis[u] && !dfs(u))
            return false;
        else if (anc[u])
            return false;
    }
    anc[v] = false;
    ord.push_back(v);
    return true;
}

// check long long
void solve() {
    cin >> n >> m;
    adj.assign(n, vector<int>());
    vis.assign(n, 0);
    anc.assign(n, 0);
    vector<pii> unordered_edges;
    vector<pii> res;
    for (int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        if (t == 0)
            unordered_edges.push_back({u, v});
        else {
            adj[u].push_back(v);
            res.push_back({u, v});
        }
    }
    //cout << res.size() << " ";
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            bool r = dfs(i);
            if (!r) {
                cout << "NO\n";
                return;
            }
        }
    }
    unordered_map<int,int> mp;
    reverse(ord.begin(), ord.end());
    for (int i = 0; i < n; i++) {
        mp[ord[i]] = i;
    }
    for (pii e : unordered_edges) {
        if (mp[e.first] < mp[e.second])
            res.push_back({e.first, e.second});
        else
            res.push_back({e.second, e.first});
    }
    assert(res.size() == m);
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        cout << res[i].first+1 << " " << res[i].second+1 << "\n";
    }
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
