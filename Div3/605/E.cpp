#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> vis(n, 0);
    vector<int> d(n, 1e9);
    vector<vector<int>> adj(n);
    for (int v = 0; v < n; v++) {
        if (v-a[v] >= 0)
            adj[v-a[v]].push_back(v);
        if (v+a[v] < n)
            adj[v+a[v]].push_back(v);
    }
    queue<int> q;
    for (int v = 0; v < n; v++) {
        if (v-a[v] >= 0 && a[v-a[v]] % 2 != a[v] % 2) {
            q.push(v);
            d[v] = 1;
            vis[v] = true;
        }
        if (v+a[v] < n && a[v+a[v]] % 2 != a[v] % 2) {
            q.push(v);
            d[v] = 1;
            vis[v] = true;
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                d[u] = min(d[u], d[v] + 1);
                q.push(u);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << (d[i] == 1e9 ? -1 : d[i]) << " ";
    cout << "\n";
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
