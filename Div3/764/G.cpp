#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<int> parent;
vector<int> sz;

void init() {
    parent.resize(n);
    sz.assign(n, 1);
    for (int v = 0; v < n; ++v)
        parent[v] = v;
}
int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]); // Optimizes depth 
}
bool union_sets(int v, int u) {
    v = find_set(v), u = find_set(u);
    if (v == u)
        return false;
    if (sz[v] < sz[u])
        swap(v, u); // Optimizes depth
    parent[u] = v;
    sz[v] += sz[u];
    return true;
}

// check long long
void solve() {
    cin >> n >> m;
    vector<array<ll,3>> edges;
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, u, v});
    }
    ll cost = 0;
    ll res = 0;
    for (ll bit = 31; bit >= 0; bit--) {
        ll mask = (1LL << bit) - 1LL;
        ll mx = res + mask;
        init();
        for (auto& e : edges) {
            if ((e[0] | mx) <= mx) {
                union_sets(e[1], e[2]);
            }
        }
        int num_groups = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                num_groups++;
        if (num_groups > 1) {
            res |= (1LL << bit);
        }
    }
    cout << res << "\n";
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
