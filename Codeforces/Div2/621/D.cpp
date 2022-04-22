#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m >> k;
    vector<int> sp;
    for (int i = 0; i < k; i++) {
        int a; cin >> a; a--;
        sp.push_back(a);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ds(n, 1e9), dt(n, 1e9);
    auto bfs = [&](vector<int>& d, int s) {
        queue<int> q;
        vector<bool> vis(n, 0);
        q.push(s);
        d[s] = 0;
        vis[s] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (!vis[u]) {
                    vis[u] = true;
                    q.push(u);
                    d[u] = d[v]+1;
                }
            }
        }
    };
    bfs(ds, 0);
    bfs(dt, n-1);
    int max_dist = 0;
    vector<pii> pd;
    for (int v : sp) {
        pd.push_back({ds[v], dt[v]});
    }
    sort(pd.begin(), pd.end(), [&](pii a, pii b) { return a.first - a.second < b.first - b.second; });
    vector<int> sf(k);
    int mx = 0;
    for (int i = k-1; i >= 0; i--) {
        mx = max(mx, pd[i].second);
        sf[i] = mx;
    }
    int i = 0;
    for (int i = 0; i < k-1; i++) {
        max_dist = max(min(pd[i].first + 1 + sf[i+1], dt[0]), max_dist);
    }
    cout << max_dist << "\n";
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
