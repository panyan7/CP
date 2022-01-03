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
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n, 0));
    vector<int> cnt(n, 0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
            cnt[a[i][j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] != 2) {
            cout << "-1\n";
            return;
        }
    }
    init();
    for (int i = 0; i < n; i++) {
        union_sets(a[0][i], a[1][i]);
    }
    unordered_map<int, vector<int>> sets;
    for (int i = 0; i < n; i++)
        sets[find_set(i)].push_back(i);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        adj[a[0][i]].push_back(i);
        adj[a[1][i]].push_back(i);
    }
    vector<bool> vis(n, 0);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        vector<int> f, nf;
        function<void(int)> dfs = [&](int i) {
            vis[i] = true;
            for (int j : adj[a[1][i]]) {
                if (vis[j])
                    continue;
                if (a[1][j] == a[1][i]) {
                    f.push_back(j);
                    swap(a[1][j], a[0][j]);
                } else {
                    nf.push_back(j);
                }
                dfs(j);
            }
        };
        nf.push_back(i);
        dfs(i);
        if (f.size() < nf.size()) {
            for (int x : f)
                res.push_back(x);
        } else {
            for (int x : nf)
                res.push_back(x);
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i]+1 << " ";
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
