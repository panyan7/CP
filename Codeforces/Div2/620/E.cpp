#include <bits/stdc++.h>
using namespace std;

const int lim = 17;
int n, q;
vector<vector<int>> G;
int u, v, x, y, a, b, k;
vector<int> depth;
vector<vector<int>> parent;

void build(int v, int p) {
    depth[v] = depth[p] + 1;
    parent[v][0] = p;
    for (int i = 1; i <= lim; ++i) {
        parent[v][i] = parent[parent[v][i-1]][i-1];
    }
    for (int u : G[v])
        if (u != p)
            build(u, v);
}

int query(int u, int v) {
    int len = 0;
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = lim; k >= 0; --k) {
        if (depth[parent[v][k]] >= depth[u]) {
            v = parent[v][k];
            len += (1 << k);
        }
    }
    if (u == v)
        return len;
    for (int k = lim; k >= 0; --k) {
        if (parent[v][k] != parent[u][k]) {
            u = parent[u][k];
            v = parent[v][k];
            len += (1 << (k+1));
        }
    }
    return len+2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    G.assign(n+1, vector<int> (0));
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    depth.assign(n+1, 0);
    parent.assign(n+1, vector<int> (lim+1, 0));

    build(1, 0);

    cin >> q;
    while (q--) {
        cin >> x >> y >> a >> b >> k;
        int ans1 = query(a, b);
        int ans2 = min(query(a, x) + query(y, b), query(a, y) + query(x, b)) + 1;
        int ans = 1e9+7;
        if (ans1 % 2 == k % 2)
            ans = ans1;
        if (ans2 % 2 == k % 2)
            ans = min(ans, ans2);
        cout << (ans <= k ? "YES" : "NO") << "\n";
    }
    return 0;
}
