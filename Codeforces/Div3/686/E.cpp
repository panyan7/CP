#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;
int cycle_start, cycle_end;
vector<ll> cnt;
vector<int> cycle;

bool dfs(int v, int par) { // passing vertex and its parent vertex
    vis[v] = true;
    for (int u : adj[v]) {
        if (u == par)
            continue; // skipping edge to parent vertex
        if (vis[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

bool find_cycle() {
    vis.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    for (int v = 0; v < n; v++) {
        if (!vis[v] && dfs(v, parent[v]))
            break;
    }
    if (cycle_start == -1)
        return false;
    cycle.clear();
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    return true;
}

void dfs2(int v, int r) {
    vis[v] = true;
    cnt[r]++;
    for (int u : adj[v])
        if (!vis[u])
            dfs2(u, r);
}

void solve() {
    cin >> n;
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = find_cycle();
    assert(ok);
    cycle.pop_back();
    vis.assign(n, 0);
    for (int v : cycle)
        vis[v] = true;
    cnt.assign(n, 0);
    for (int v : cycle) {
        dfs2(v, v);
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        // cout << cnt[i] << " ";
        res += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << n * (n - 1) - res << "\n";
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
