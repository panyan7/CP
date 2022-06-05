#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct LCA {
    int n, lim;
    int timer = 0;
    vector<vector<int>> anc;
    vector<vector<int>> adj;
    vector<int> tin, tout;
private:
    void dfs(int v, int p) {
        tin[v] = ++timer;
        anc[v][0] = p;
        for (int i = 1; i <= lim; i++) {
            anc[v][i] = anc[anc[v][i-1]][i-1];
        }
        for (int u : adj[v]) {
            if (u != p) {
                dfs(u, v);
            }
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
public:
    LCA(int n) : n(n), lim(ceil(log2(n))) {
        tin.assign(n, 0);
        tout.assign(n, 0);
        adj.resize(n);
        anc.assign(n, vector<int>(lim+1, 0));
    }
    void init(int root = 0) {
        dfs(root, root);
    }
    int query(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = lim; i >= 0; --i) {
            if (!is_ancestor(anc[u][i], v))
                u = anc[u][i];
        }
        return anc[u][0];
    }
};
#define SZ 1000 + 10

int n, m;
ll costs[SZ];
ll a[SZ];
bool valid[SZ];

void update(LCA& G, int curr, int p, int val) {
    costs[curr] = val;
    valid[curr] = true;
    for (int v: G.adj[curr]) {
        if (v != p) {
            valid[curr] = false;
            update(G, v, curr, val + a[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    n++; // fake root is 0
    LCA G(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    vector<int> indeg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.adj[u].push_back(v);
        G.adj[v].push_back(u);
        indeg[v]++;
    }
    for (int i = 1; i < n; i++) {
        if (indeg[i] == 0) {
            G.adj[0].push_back(i);
            G.adj[i].push_back(0);
        }
    }
    G.init();

    update(G, 0, -1, 0);

    ll cost = 1000000000;
    for (int i = 1; i < n; i++) {
        if (!valid[i]) continue;
        for (int j = 1; j < n; j++) {
            if (!valid[j]) continue;
            if (i == j) continue;
            ll curr = costs[i] + costs[j] - costs[G.query(i, j)];
            cost = min(cost, curr);
        }
    }

    cout << cost << endl;


    return 0;
}

